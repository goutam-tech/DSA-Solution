import os
import re

PLATFORMS = ["LeetCode", "GFG", "HackerRank"]
LEVELS = ["Basic", "Easy", "Medium", "Hard"]
SOLUTION_EXTS = ["py", "cpp", "sql", "cs"]

# LANG_ICON = {
#     "py": "🐍 Python",
#     "cpp": "💻 C++",
#     "sql": "🗄️ SQL",
#     "cs": "🔷 C#",
# }
LANG_ICON = {
    "py": "<img src='https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg' width='18' height='18' alt='Python'/> Python",
    "cpp": "<img src='https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg' width='18' height='18' alt='C++'/> C++",
    "sql": "<img src='https://cdn.jsdelivr.net/gh/devicons/devicon/icons/azuresqldatabase/azuresqldatabase-original.svg' width='18' height='18' alt='SQL'/> SQL",
    "cs": "<img src='https://cdn.jsdelivr.net/gh/devicons/devicon/icons/csharp/csharp-original.svg' width='18' height='18' alt='C#'/> C#",
}

ID_RE = re.compile(
    r"^##\s*Id\s*-\s*(\d+)\s*\[(.+?)\]"
    r"\((\S+?)\)"
    r"(?:\s*\{(.*?)\})?$"
)


def find_folder(parent, names):
    """Case-insensitive folder search returning actual on-disk name."""
    if not os.path.isdir(parent):
        return None

    for item in os.listdir(parent):
        path = os.path.join(parent, item)
        if item.lower() in names and os.path.isdir(path):
            return item

    return None


def find_solution(platform, level, pid):
    """Find solution file with flexible casing for folder names."""
    solution_folder = find_folder(platform, {"solution", "soultion"})
    if not solution_folder:
        return None, None

    root = os.path.join(platform, solution_folder)
    level_folder = find_folder(root, {level.lower()})
    if not level_folder:
        return None, None

    folder = os.path.join(root, level_folder)
    for file in os.listdir(folder):
        name, ext = os.path.splitext(file)
        ext = ext.replace(".", "").lower()

        if name == str(pid) and ext in SOLUTION_EXTS:
            return (
                os.path.join(folder, file).replace("\\", "/"),
                ext,
            )

    return None, None


def parse_file(path):
    """Parse difficulty markdown file into problem dicts."""
    problems = []
    with open(path, encoding="utf-8") as file:
        for line in file:
            line = line.strip()
            if not line.startswith("## Id"):
                continue

            match = ID_RE.match(line)
            if not match:
                continue

            pid, title, url, topics = match.groups()
            topics = [x.strip() for x in topics.split(",")] if topics else []

            problems.append(
                {
                    "id": pid,
                    "title": title.strip(),
                    "url": url.strip(),
                    "topics": topics,
                }
            )

    return problems


def remove_duplicates(items):
    """Filter duplicate problems by (id, title)."""
    seen = set()
    result = []
    for item in items:
        key = (item["id"], item["title"])
        if key not in seen:
            seen.add(key)
            result.append(item)
    return result


def progress_bar(done: int, total: int, size: int = 10) -> str:
    """Generates a progress bar with correct rounding and clamping."""
    if total <= 0:
        return "░" * size

    filled = round(size * (done / total))
    filled = max(0, min(size, filled))

    return "█" * filled + "░" * (size - filled)


def build_table(problems, platform, level):
    """Construct Markdown table for a specific platform difficulty."""
    rows = []
    for problem in sorted(problems, key=lambda x: int(x["id"])):
        solution, ext = find_solution(platform, level, problem["id"])

        if solution:
            icon = LANG_ICON.get(ext, ext)
            link = f"[Solution]({solution}) {icon}"
        else:
            link = f"[Problem]({problem['url']}) 🔲"

        topics = " ".join([f"`{t}`" for t in problem["topics"]])
        rows.append(f"| {problem['id']} | {problem['title']} | {link} | {topics} |")

    return "\n".join(
        [
            "| # | Problem | Solution | Topics |",
            "|---|---|---|---|",
            *rows,
        ]
    )


def generate_readme():
    output = [
        "# 🚀 DSA Problem Solving Dashboard",
        "",
        "> A structured collection of solved Data Structures & Algorithms problems.",
        "",
        "![DSA](https://img.shields.io/badge/DSA-Practice-blue?style=for-the-badge&logo=datadog&logoColor=white)",
        "![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)",
        "![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)",
        "![C#](https://img.shields.io/badge/C%23-239120?style=for-the-badge&logo=csharp&logoColor=white)",
        "![SQL](https://img.shields.io/badge/SQL-CC292B?style=for-the-badge&logo=microsoftsqlserver&logoColor=white)",
        "![LeetCode](https://img.shields.io/badge/LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=black)",
        "![GeeksforGeeks](https://img.shields.io/badge/GeeksforGeeks-298D46?style=for-the-badge&logo=geeksforgeeks&logoColor=white)",
        "![HackerRank](https://img.shields.io/badge/HackerRank-00EA64?style=for-the-badge&logo=hackerrank&logoColor=black)",
        "",
        "---",
        "",
        "## 📚 Platforms",
        "",
    ]

    stats = []

    for platform in PLATFORMS:
        total = 0
        solved = 0

        for level in LEVELS:
            file = os.path.join(platform, "Question", f"{level}.md")
            if not os.path.isfile(file):
                continue

            problems = remove_duplicates(parse_file(file))
            total += len(problems)

            solved += sum(
                1 for p in problems if find_solution(platform, level, p["id"])[0]
            )

        stats.append((platform, solved, total))

    output.extend(
        [
            "| Platform | Progress |",
            "|---|---|",
        ]
    )

    for name, done, total in stats:
        output.append(f"| {name} | {done}/{total} `{progress_bar(done, total)}` |")

    output.extend(
        [
            "",
            "---",
            "",
        ]
    )

    for platform in PLATFORMS:
        output.extend(
            [
                f"## {platform}",
                "",
            ]
        )

        for level in LEVELS:
            file = os.path.join(platform, "Question", f"{level}.md")
            if not os.path.isfile(file):
                continue

            problems = remove_duplicates(parse_file(file))
            if not problems:
                continue

            solved = sum(
                1 for p in problems if find_solution(platform, level, p["id"])[0]
            )

            output.extend(
                [
                    f"### {level} ({solved}/{len(problems)} solved)",
                    "",
                    build_table(problems, platform, level),
                    "",
                ]
            )

    output.extend(
        [
            "---",
            "",
            "## ⭐ Goal",
            "",
            "Solve 1000+ DSA problems.",
            "",
            "Topics:",
            "",
            "- Arrays",
            "- Strings",
            "- Linked Lists",
            "- Trees",
            "- Graphs",
            "- Dynamic Programming",
            "",
            "Generated automatically using Python.",
        ]
    )

    with open("README.md", "w", encoding="utf-8") as file:
        file.write("\n".join(output) + "\n")

    print("README.md successfully generated")


if __name__ == "__main__":
    generate_readme()
