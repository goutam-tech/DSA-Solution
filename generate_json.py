import json
import re
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent

def find_solution(platform, difficulty, problem_id):

    if platform == "CodeForce":
        solution_folder = BASE_DIR / platform / "Solution"

        if not solution_folder.exists():
            return []

        solutions = []

        for file in solution_folder.iterdir():
            if file.stem == problem_id:
                solutions.append(f"{platform}/Solution/{file.name}")

        return solutions

    solution_folder = BASE_DIR / platform / "Solution" / difficulty

    if not solution_folder.exists():
        return []

    for file in solution_folder.iterdir():
        if file.stem == problem_id:
            return [f"{platform}/Solution/{difficulty}/{file.name}"]

    return []


def parse_codeforce_markdown(file_path):

    problems = {}

    if not file_path.exists():
        return problems

    content = file_path.read_text(encoding="utf-8")

    pattern = re.compile(
        r"##\s+\[.*?\.\s*(.*?)\]\(https://codeforces\.com/problemset/problem/(\d+)/([A-Z])\)"
    )

    matches = pattern.findall(content)

    for name, contest_id, problem_letter in matches:
        problem_id = f"{contest_id}{problem_letter}"

        problems[problem_id] = {
            "name": name.strip(),
            "url": f"https://codeforces.com/contest/{contest_id}/problem/{problem_letter}",
            "difficulty": file_path.stem,
            "solutions": find_solution("CodeForce", file_path.stem, problem_id),
        }

    return problems

def parse_markdown(file_path, difficulty, platform):

    if platform == "CodeForce":
        return parse_codeforce_markdown(file_path)

    problems = {}

    if not file_path.exists():
        return problems

    content = file_path.read_text(encoding="utf-8")

    pattern = re.compile(r"## Id - (\d+)\s+\[(.*?)\]\((.*?)\)\s+\{(.*?)\}")

    matches = pattern.findall(content)

    for problem_id, name, url, topics in matches:
        problems[problem_id] = {
            "name": name.strip(),
            "url": url.strip(),
            "topics": [topic.strip() for topic in topics.split(",")],
            "difficulty": difficulty,
            "solutions": find_solution(platform, difficulty, problem_id),
        }

    return problems

def generate_platform_json(platform_path):

    platform = platform_path.name

    question_folder = platform_path / "Question"

    if not question_folder.exists():
        return

    all_problems = {}

    markdown_files = {
        "Easy": question_folder / "Easy.md",
        "Medium": question_folder / "Medium.md",
        "Hard": question_folder / "Hard.md",
    }

    if platform == "CodeForce":
        for file in question_folder.glob("*.md"):
            data = parse_markdown(file, file.stem, platform)

            all_problems.update(data)
    else:
        for difficulty, file in markdown_files.items():
            data = parse_markdown(file, difficulty, platform)

            all_problems.update(data)

    output_file = platform_path / f"{platform}.json"

    with open(output_file, "w", encoding="utf-8") as json_file:
        json.dump(all_problems, json_file, indent=2, ensure_ascii=False)

    print(f"✓ {platform}.json created ({len(all_problems)} problems)")

def main():

    for folder in BASE_DIR.iterdir():
        if folder.is_dir():
            generate_platform_json(folder)


if __name__ == "__main__":
    main()