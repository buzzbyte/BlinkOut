# BlinkOut
**BlinkOut** (or just **blink**) outputs a red, bold blinking text on a console with a given message. It also uses the famous "cowsay" command to make the speach bubble text blink in red!

##Building/Compiling
There is no Makefile yet, which means everything has to be done manually. Luckly, it only needs one command in order to compile it:
```
$ g++ blinking-text.cpp -o blink
```
If you want to install it, however, you'll need to do that manually (but you really don't have to).

##Usage and Examples
Download the .ZIP file, extract it, then ```cd``` to wherever you extracted it at.
```
$ ./blink --help
USAGE: ./blink [OPTIONS]... [MESSAGE]...
Displays a red, bold blinking text on a console with a MESSAGE.

OPTIONS:
-h, --help    , --usage                Displays this help message.
-v, --verbose , --debug                Displays debuging information.
-m, --moo     , --cow       [MSG]      Executes the 'cowsay' command with given MESSAGE (if any).
    --no-blink, --noblink   [MSG|OPT]  Displays MESSAGE or another OPTION's output without blinking.

MSG=MESSAGE; OPT=OPTIONS

Examples:
    ./blink "I'm blinking!"                       Outputs a blinking red text.
    ./blink -m "My words blink!"                  Draws a cow with a blinking red text in speech bubble.
    ./blink --noblink "I'm not blinking."         Outputs a non-blinking red text.
    ./blink --noblink -m "My words don't blink."  Draws a cow with a non-blinking red text in speech bubble.
You can even try a combination!
    ./blink "I'm blinking!" -m "Hi, blinking!" --noblink "Now I'm not blinking." -m "Aww.."
```

##TODO
* Make cow's eyes blink.
* Make it more customizable
* DON'T abandon this project (it happens often).

##Bugs/Issues
[Create an issue](https://github.com/buzzbyte/BoxPL/issues/new) on GitHub and I will see what I can do to fix it.
