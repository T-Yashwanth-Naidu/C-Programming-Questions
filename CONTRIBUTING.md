# Contributing

Thanks for your interest in this repository. This is a personal collection of C programming exercises, but contributions are welcome - whether it is fixing a bug, improving an explanation, or adding a new problem.

This repo is meant for learners at all levels - beginners, intermediates, and experienced developers. Solutions can vary widely in style, structure, and complexity, and that diversity is part of the value. There is no single "correct" way to solve these problems, and this repo does not enforce a particular coding style.

## Repository Structure

Each topic has its own folder (Arrays, Bit_Manipulations, Linked_List, etc.). New problems should go into the relevant folder. If a topic does not exist yet, feel free to create a new folder for it.

## Submitting Changes

1. Fork the repository.
2. Create a feature branch from `main`:
   `git checkout -b your-feature-name`
3. Make your changes. Keep commits focused and well-described.
4. Push your branch to your fork.
5. Open a pull request against `main`.

All pull requests require at least one approving review before merging.

## Solution Files

When contributing a solution to a problem, please follow these conventions:

- **Single-file solutions.** Name your file `<your-name>_solution.c`   (e.g., `yashwanth_solution.c`). Place it directly  in the problem's folder. This keeps multiple solutions to the same problem  distinguishable and credits each contributor.

- **Multi-file solutions or build systems.** If your solution spans multiple  files (header + source, multiple modules, a CMake project, a Makefile, etc.), create a `solutions/<your-name>/` subdirectory inside the problem
  folder and place all your files there. For example:  

```
Bit-Manipulations/
└── Rotate_Bits/
    └── Solutions/
        └── your_name/
            ├── your_file_1.c
            ├── your_file_2.c
            └── Makefile (or CMakeLists.txt, etc.)
```

This keeps the top level clean while letting contributors structure  larger solutions however they prefer.

- **Author header.** Include an author header at the top of your main file in this format:

```c
  // @Author: Your Name (Your GitHub URL)
```

  Example:

```c
  // @Author: Yashwanth Naidu Tikkisetty (https://github.com/T-Yashwanth-Naidu)
```

  This makes ownership clear and lets readers find your other work.

- **Style and structure.** Code your solution however you like. Different approaches teach different things, and seeing varied styles is useful for learners. Some explanation in comments is appreciated so others can follow your thinking, but how much and in what form is up to you.

## Pull Request Guidelines

- Describe what your PR changes and why.
- If you are adding a new problem, include the problem statement somewhere in your solution (file header, README, or commit message).
- If you are fixing a bug, mention what the bug was.
- Keep PRs focused on one change. Do not mix unrelated edits.

## Reporting Issues

If you find a bug or have a suggestion, open an issue describing:

- What you expected to happen
- What actually happened
- The file or section involved
- Steps to reproduce, if applicable

## License

By contributing, you agree that your contributions will be licensed under the same license as the repository.
