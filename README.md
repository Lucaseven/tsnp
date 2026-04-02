# tsnp
===
### Introduction
tsnp is an attempt at making a no-fluff, no-nonsense MS Paint clone
art program for Unix-like machines. This is a shared project for learning
and personal use purposes; don't expect too much if you stumble across this
randomly.

### Dependencies
For a project this small scale, it suffices to simply get the latest
stable version of the tsnp's dependencies available for your environment for now.
Please check detailed instructions for installation and configuration for your
own system's environment. This list and/or respective software versions may change
as the project progresses.

- Version control: `git`
- Build system (generator): `cmake`
- A working C++ compiler: `gcc` or `clang`

### Build and run instructions

1. Open your terminal application of choice

2. In any directory, clone this repository and navigate to the `tsnp`
directory:
```
git clone https://github.com/Lucaseven/tsnp.git
cd tsnp
```

3. Build the program using the following commands (run them all first):
```
cmake -B build/ -S src/
cmake --build build/
```

4. Test running the program:
```
./build/tsnp
```

That's it! Move it around, move it into your `bin` directory, whatever.

### Contributing
-----------------
To contribute to tsnp, make sure you have performed the entire 4 steps
in [Build and run](#build-and-run-instructions).

If the program runs properly, feel free to make any changes to the files
in `src`. Once you're satisfied, commit the changes to your local branch,
and then open a PR. We'll review the PR hopefully in just a few days from
it being open.

### Credits
-----------
This README was written by: Gumperto.
