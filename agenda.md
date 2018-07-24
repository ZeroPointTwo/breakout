# Agenda

## Documents
* Git
	* [Command help](https://git-scm.com/docs)
	* [Visual Command Cheat Sheet](http://ndpsoftware.com/git-cheatsheet.html): Click on different work stages to see how the different commands relate.
	* [Git for Perforce Users](https://cedrics.gitbooks.io/git-for-perforce-users/content/index.html): I don't know enough Perforce to say if this is good, but it seemed helpful.
	* [Visualizing Git](http://git-school.github.io/visualizing-git/): Lets you issue Git commands and displays a graph of how all of the nodes are affected.
* Github
	* Basic [Github Tutorial](https://guides.github.com/activities/hello-world/)
  
## 24 July 2018

* Discuss Git
	* Create a Day1 branch
		* `git branch origin/master day1`
	* Make a readme change
		* `git checkout day1`
	* Create a pull request
		* `git add .`
		* `git status`
		* `git diff`
		* `git commit -m "Commit message"`
		* `git push`
	* Merge the pull request
	* Pull the new master branch
		* `git pull`
		* `git fetch`
		* `git checkout master`
		* `git merge origin/master`
* Discuss CMake
	* Why do people use it?
	* Differences between Generators
		* Multi configurations
		* Compile command databases
		* Toolchains
	* How to use CMake on existing CMake projects
		* [RapidCheck Example](https://github.com/emil-e/rapidcheck)
		*  cmake.exe
			*  cmake .. --config Debug
			*  cmake --build . --config Debug
		*  cmake-gui.exe
    * How to create a CMake project
* Discuss Conan
	* What is it?
	* How to pull dependencies
	* How to integrate with CMake
* Setup Breakout project
	* Use day1 branch
	* Reference CMake branch to setup Conan, CMake, and a skeleton project
		* Talk about what each part of the config files does
		* Talk through batch files for project workflow
* Discuss Clang tools we will use
	* Clang-format
	* Clang-tidy
	* Clang VS Power Tools

## 17 July 2018

* Discuss Git
	* ~~Create a new repo on Github~~
	* ~~Clone a repo~~
		* ~~Git Bash~~
			* ~~`git clone location`~~
		* ~~Git Gui~~
	* ~~Clone the [breakout](https://github.com/ZeroPointTwo/breakout) repo~~
	* Create a Day1 branch
		* `git branch origin/master day1`
	* Make a readme change
		* `git checkout day1`
	* Create a pull request
		* `git add .`
		* `git status`
		* `git diff`
		* `git commit -m "Commit message"`
		* `git push`
	* Merge the pull request
	* Pull the new master branch
		* `git pull`
		* `git fetch`
		* `git checkout master`
		* `git merge origin/master`
* Discuss CMake
	* Why do people use it?
	* Differences between Generators
		* Multi configurations
		* Compile command databases
		* Toolchains
	* How to use CMake on existing CMake projects
		* [RapidCheck Example](https://github.com/emil-e/rapidcheck)
		*  cmake.exe
			*  cmake .. --config Debug
			*  cmake --build . --config Debug
		*  cmake-gui.exe
    * How to create a CMake project
* Discuss Conan
	* What is it?
	* How to pull dependencies
	* How to integrate with CMake
* Setup Breakout project
	* Use day1 branch
	* Reference CMake branch to setup Conan, CMake, and a skeleton project
		* Talk about what each part of the config files does
		* Talk through batch files for project workflow
* Discuss Clang tools we will use
	* Clang-format
	* Clang-tidy
	* Clang VS Power Tools
