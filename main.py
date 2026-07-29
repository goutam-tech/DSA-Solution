import json
import os
from textwrap import dedent

PLATFORM_FILES = {
    "LeetCode": "LeetCode/LeetCode.json",
    "GFG": "GFG/GFG.json",
    "Hackerrank": "HackerRank/HackerRank.json",
    "CodeForce": "CodeForce/CodeForce.json",
}

LANG_ICON = {
    "py": "<img src='https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg' width='18' height='18' alt='Python'/>",
    "cpp": "<img src='https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg' width='18' height='18' alt='C++'/>",
    "sql": "<img src='https://cdn.jsdelivr.net/gh/devicons/devicon/icons/azuresqldatabase/azuresqldatabase-original.svg' width='18' height='18' alt='SQL'/>",
    "cs": "<img src='https://cdn.jsdelivr.net/gh/devicons/devicon/icons/csharp/csharp-original.svg' width='18' height='18' alt='C#'/>",
}

def generate_section(platform, problems):
    section = f"## {platform}\n"

    if platform == "CodeForce":
        section += "\n| Id | Problem | Difficulty | Solutions |\n"
        section += "|----|---------|------------|-----------|\n"

        for pid, pdata in problems.items():
            solution_links = []

            for sol in pdata.get("solutions", []):
                ext = os.path.splitext(sol)[1].replace(".", "")
                icon = LANG_ICON.get(ext, "")
                solution_links.append(f"[{os.path.basename(sol)}]({sol}) {icon}")

            solution_links_str = ", ".join(solution_links) if solution_links else "—"

            section += (
                f"| {pid} | "
                f"[{pdata['name']}]({pdata['url']}) | "
                f"{pdata['difficulty']} | "
                f"{solution_links_str} |\n"
            )

        return section

    grouped = {}

    for pid, pdata in problems.items():
        for topic in pdata["topics"]:
            grouped.setdefault(topic, []).append((pid, pdata))

    for topic, entries in grouped.items():
        section += f"\n### {topic}\n"
        section += "| Id | Problem | Difficulty | Solutions | Topics |\n"
        section += "|----|---------|------------|-----------|--------|\n"

        for pid, pdata in entries:
            solution_links = []

            for sol in pdata.get("solutions", []):
                ext = os.path.splitext(sol)[1].replace(".", "")
                icon = LANG_ICON.get(ext, "")

                solution_links.append(f"[{os.path.basename(sol)}]({sol}) {icon}")

            solution_links_str = ", ".join(solution_links) if solution_links else "—"

            section += (
                f"| {pid} | "
                f"[{pdata['name']}]({pdata['url']}) | "
                f"{pdata['difficulty']} | "
                f"{solution_links_str} | "
                f"{', '.join(pdata['topics'])} |\n"
            )

    return section

def main():
    readme = dedent("""\
            # 🚀 DSA Problem Solving Dashboard

            > A structured collection of solved Data Structures & Algorithms problems.

            ![DSA](https://img.shields.io/badge/DSA-Practice-blue?style=for-the-badge&logo=datadog&logoColor=white)
            ![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
            ![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
            ![C#](https://img.shields.io/badge/C%23-239120?style=for-the-badge&logo=csharp&logoColor=white)
            ![SQL](https://img.shields.io/badge/SQL-CC292B?style=for-the-badge&logo=microsoftsqlserver&logoColor=white)
            ![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

            ![LeetCode](https://img.shields.io/badge/LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=black)
            ![GeeksforGeeks](https://img.shields.io/badge/GeeksforGeeks-298D46?style=for-the-badge&logo=geeksforgeeks&logoColor=white)
            ![HackerRank](https://img.shields.io/badge/HackerRank-00EA64?style=for-the-badge&logo=hackerrank&logoColor=black)
            ![Codeforces](https://img.shields.io/badge/Codeforces-1F8ACB?style=for-the-badge&logo=codeforces&logoColor=white)

            """)

    for platform, file in PLATFORM_FILES.items():
        if os.path.exists(file):
            with open(file, "r", encoding="utf-8") as f:
                problems = json.load(f)
            readme += generate_section(platform, problems)
            readme += "\n\n"

    with open("README.md", "w", encoding="utf-8") as f:
        f.write(readme)

    print("README.md updated successfully!")


if __name__ == "__main__":
    main()