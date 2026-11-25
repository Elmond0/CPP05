*This project has been created as part of the 42 curriculum by elmondo.*

# <img align="middle" height="115" src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/numbered_cpps/CPP05.png" alt="CPP05 badge"/> <picture><source media="(prefers-color-scheme: dark)" srcset="https://readme-typing-svg.demolab.com/?font=Fira+Code&weight=600&size=55&pause=1000&color=58A6FF&vCenter=true&width=400&height=80&lines=CPP05"><source media="(prefers-color-scheme: light)" srcset="https://readme-typing-svg.demolab.com/?font=Fira+Code&weight=600&size=55&pause=1000&color=0366D6&vCenter=true&width=400&height=80&lines=CPP05"><img align="middle" src="https://readme-typing-svg.demolab.com/?font=Fira+Code&weight=600&size=55&pause=1000&color=0366D6&vCenter=true&width=400&height=80&lines=CPP05" alt="CPP05"/></picture>

[![Common Core](https://img.shields.io/badge/-Common%20Core-24292e?style=flat&logo=data:image/svg%2Bxml;base64,PHN2ZyByb2xlPSJpbWciIHZpZXdCb3g9IjAgMCAyNCAzNCIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj48dGl0bGU+NDI8L3RpdGxlPjxkZXNjPkxvZ28gNDIgY29uIHBhZGRpbmcgaW5mZXJpb3JlOiBHaXRIdWIgcmltdW92ZSBnbGkgYXR0cmlidXRpIHN0eWxlIGRhbCBtYXJrZG93biwgcXVpbmRpIGlsIG1hcmdpbmUgY2hlIGFsbGluZWEgbCdpY29uYSBhbCB0ZXN0byBkZWwgdGl0b2xvIGUnIGluY29ycG9yYXRvIG5lbCB2aWV3Qm94LiBJbCBnbGlmbyBvY2N1cGEgeSAzLjU3NC0yMC40MjYgZSBzb3R0byByZXN0YW5vIDEzLjU3NCB1bml0YScgdnVvdGU6IHJlc28gYSA0MnB4IGNvbiBhbGlnbj1taWRkbGUsIGlsIGdsaWZvIHN0YSB+MnB4IHNvcHJhIGxhIGJhc2VsaW5lIGRlbCB0aXRvbG8uIFBlciBhbHphcmxvIGFuY29yYSBzZXJ2b25vICsxIHVuaXRhJyBkaSB2aWV3Qm94IG9nbmkgKzEuMnB4IGRpIGhlaWdodCAoY2lyY2EgKzAuNnB4IGRpIHNvbGxldmFtZW50bywgYSBwYXJpdGEnIGRpIGRpbWVuc2lvbmUgZGVsIGdsaWZvKS48L2Rlc2M+PHN0eWxlPnBhdGh7ZmlsbDojMDAwMDAwfSBAbWVkaWEgKHByZWZlcnMtY29sb3Itc2NoZW1lOmRhcmspe3BhdGh7ZmlsbDojRkZGRkZGfX08L3N0eWxlPjxwYXRoIGQ9Ik0xOS41ODEgMTYuODUxSDI0di00LjQzOVpNMjQgMy41NzRoLTQuNDE5djQuNDJsLTQuNDE5IDQuNDE4djQuNDRoNC40MTl2LTQuNDRMMjQgNy45OTNabS00LjQxOSAwaC00LjQxOXY0LjQyem0tNi4zMjQgOC44MzhINC40MTlsOC44MzgtOC44MzhIOC44MzhMMCAxMi40MTJ2My41OTVoOC44Mzh2NC40MTloNC40MTl6Ii8+PC9zdmc+Cg==)](https://profile.intra.42.fr/users/elmondo)
![Language](https://img.shields.io/badge/language-C%2B%2B98-blue)
![Flags](https://img.shields.io/badge/flags--Wall%20--Wextra%20--Werror-passing-brightgreen)
![Valgrind](https://img.shields.io/badge/valgrind-no%20leaks-brightgreen)

> Repetition and exceptions: a small bureaucracy simulation where grade constraints are enforced by exceptions.

---

## 📖 Description

`CPP05` is Module 05 of the 42 **C++ modules**. Every exercise is written in **C++98** and compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

What this module covers:

- `try` / `catch` and custom exception classes derived from `std::exception`
- Nested exception classes and `what()` overrides
- Abstract base class `AForm` and concrete forms
- Factory-style creation without `if/else` chains (`Intern`)
- `const` members that must be initialized in the initialization list

---

## 🗂️ Exercises

| Directory | Exercise | Executable | Description |
|:---------:|----------|:----------:|-------------|
| `ex00` | Mommy, when I grow up, I want to be a bureaucrat! | `Bureaucrat` | `Bureaucrat` with a grade from 1 (highest) to 150, throwing `GradeTooHighException` / `GradeTooLowException`. |
| `ex01` | Form up, maggots! | `Form` | `Form` with signing and executing grades; `Bureaucrat::signForm()`. |
| `ex02` | No, you need form 28B, not 28C... | `ManyForms` | Abstract `AForm` and `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`. |
| `ex03` | At least this beats coffee-making | `Interns` | `Intern::makeForm(name, target)` builds the right form from its name. |

---

## ⚙️ Compilation & Usage

Each exercise is independent and has its own `Makefile`:

```bash
make        # build the executable
make clean  # remove object files
make fclean # remove object files and the executable
make re     # fclean + make
```

**`ex00` — Mommy, when I grow up, I want to be a bureaucrat!**
```bash
cd ex00 && make
./Bureaucrat
```

**`ex01` — Form up, maggots!**
```bash
cd ex01 && make
./Form
```

**`ex02` — No, you need form 28B, not 28C...**
```bash
cd ex02 && make
./ManyForms
```

**`ex03` — At least this beats coffee-making**
```bash
cd ex03 && make
./Interns
```

---

## 📁 Project Structure

```
CPP05/
├── ex00/
│   ├── Bureaucrat.cpp
│   ├── Bureaucrat.hpp
│   ├── main.cpp
│   └── Makefile
├── ex01/
│   ├── Bureaucrat.cpp
│   ├── Bureaucrat.hpp
│   ├── Form.cpp
│   ├── Form.hpp
│   ├── main.cpp
│   └── Makefile
├── ex02/
│   ├── AForm.cpp
│   ├── AForm.hpp
│   ├── Bureaucrat.cpp
│   ├── Bureaucrat.hpp
│   ├── PresidentialPardonForm.cpp
│   ├── PresidentialPardonForm.hpp
│   ├── RobotomyRequestForm.cpp
│   ├── RobotomyRequestForm.hpp
│   ├── ShrubberyCreationForm.cpp
│   ├── ShrubberyCreationForm.hpp
│   ├── main.cpp
│   └── Makefile
└── ex03/
    ├── AForm.cpp
    ├── AForm.hpp
    ├── Bureaucrat.cpp
    ├── Bureaucrat.hpp
    ├── Intern.cpp
    ├── Intern.hpp
    ├── PresidentialPardonForm.cpp
    ├── PresidentialPardonForm.hpp
    ├── RobotomyRequestForm.cpp
    ├── RobotomyRequestForm.hpp
    ├── ShrubberyCreationForm.cpp
    ├── ShrubberyCreationForm.hpp
    ├── main.cpp
    └── Makefile
```

---

## 📚 Resources

- [Exceptions — cppreference](https://en.cppreference.com/w/cpp/language/exceptions)
- [std::exception — cppreference](https://en.cppreference.com/w/cpp/error/exception)
- [Factory method pattern](https://refactoring.guru/design-patterns/factory-method)
- `man 3 cout`, [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- [Valgrind](https://valgrind.org/) — memory error and leak detector used for testing

---

## 🎯 Key Takeaways

- Using **exceptions** for error handling instead of return codes.
- Designing an **abstract form hierarchy** with shared validation logic.
- Creating objects by name with a **function-pointer table**.
- Keeping all of it **leak-free** under Valgrind.
