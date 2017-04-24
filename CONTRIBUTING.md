# CONTRIBUTING

## Procedure for Contributing Code

1. If you are looking to implement LFU in a language `X`, go to the Issue Tracker and create an Issue for that langauge! After you've done that, the admin will assign that Issue to you and you can get started working on an implementation. If it already exists, try making it better!

2. Fork the project to your GitHub account and clone the project to your local repository using `git clone`. Kindly **do not do Download ZIP** as pushing the files is more tougher after that!

3. After cloning the project, create a branch in the language that you are planning to implement using `git checkout -b X` and then implementing your changes.

4. To commit your changes run the following code:
```bash
git add ---all
git commit -m "<Your commit message>"
```

5. Once you are ready to push your changes, you can do so using `git push origin X`.

6. After that go to the forked repository and send a Pull Request to the LFU repository on Web Club NITK. In the Pull Request description, kindly mention all the changes that you've done!

## Benchmarks

We have members with varying experiences in different programming languages! Want to contribute? Amazing :) Please follow guidelines as below:

* Benchmark your programs against a test suite. We will be adding the module soon. Comparing different implementations hence becomes easier.
* All code should have atleast 80% code coverage. You can use online tools to check the same. Test cases should be elaborate and should cover corner cases.