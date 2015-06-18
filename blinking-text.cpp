#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

string exec(string cmd) {
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);
    return result;
}

int main(int argc, char* argv[]){
	bool blink = true;
	for (int i = 1; i < argc; ++i) {
		string arg = argv[i];
		if ((arg == "--noblink") || (arg == "--no-blink")) {
			blink = false;
			string blnkstr = argv[i+1];
			if(i+1 < argc && blnkstr.compare(0,1,"-")) {
				cout << "\033[31;1m" << blnkstr << "\033[m" << endl;
			}
		} else if ((arg == "-v") || (arg == "--debug") || (arg == "--verbose")) {
			cout << "argc = " << argc << endl;
			for(int i = 0; i < argc; i++)
				cout << "argv[" << i << "] = " << argv[i] << endl;
		} else if ((arg == "-m") || (arg == "--moo") || (arg == "--cow")) {
			string cowstr = argv[i+1];
			if(blink) {
				if(i+1 < argc && cowstr.compare(0,1,"-")) {
					cout << exec("cowsay '\033[5;31;1m " + cowstr + " \033[m'") << endl;
				} else {
					cout << exec("cowsay '\033[5;31;1m LOLZ!! \033[m'") << endl;
				}
			} else {
				if(i+1 < argc && cowstr.compare(0,1,"-")) {
					cout << exec("cowsay '\033[31;1m " + cowstr + " \033[m'") << endl;
				} else {
					cout << exec("cowsay '\033[31;1m LOLZ!! \033[m'") << endl;
				}
			}
		} else if ((arg == "-h") || (arg == "--help") || (arg == "--usage") || (arg == "--info")) {
			//cout << "USAGE: " << argv[0] << " [message] [-m|--moo|--cow [message]] [--noblink|--no-blink [options|message]] [-v|--verbose|--debug]" << endl;
			if (arg == "--usage") {
				cout << "\033[38;5;226mUSAGE: " << argv[0] << " [OPTIONS]... [MESSAGE]...\033[m" << endl;
			} else {
				cout << "USAGE: " << argv[0] << " [OPTIONS]... [MESSAGE]..." << endl;
			}
			cout << "Displays a red, bold blinking text on a console with a MESSAGE. \033[5;31;1m Like this! \033[m" << endl;
			cout << endl;
			cout << "OPTIONS:" << endl;
			cout << "-h, --help    , --usage                Displays this help message." << endl;
			cout << "-v, --verbose , --debug                Displays debuging information." << endl;
			cout << "-m, --moo     , --cow       [MSG]      Executes the 'cowsay' command with given MESSAGE (if any)." << endl;
			cout << "    --no-blink, --noblink   [MSG|OPT]  Displays MESSAGE or another OPTION's output without blinking." << endl;
			cout << endl;
			cout << "MSG=MESSAGE; OPT=OPTIONS" << endl;
			cout << endl;
			cout << "Examples:" << endl;
			cout << "    " << argv[0] << " \"I'm blinking!\"                       Outputs a blinking red text." << endl;
			cout << "    " << argv[0] << " -m \"My words blink!\"                  Draws a cow with a blinking red text in speech bubble." << endl;
			cout << "    " << argv[0] << " --noblink \"I'm not blinking.\"         Outputs a non-blinking red text." << endl;
			cout << "    " << argv[0] << " --noblink -m \"My words don't blink.\"  Draws a cow with a non-blinking red text in speech bubble." << endl;
			cout << "You can even try a combination!" << endl;
			cout << "    " << argv[0] << " \"I'm blinking!\" -m \"Hi, blinking!\" --noblink \"Now I'm not blinking.\" -m \"Aww..\"" << endl;
			cout << endl;
			cout << "Report bugs at GitHub or something.." << endl;
			cout << endl;
			return 0;
		} else {
			if (arg == argv[1]) {
				if(blink) {
					cout << "\033[5;31;1m" << arg << "\033[m" << endl;
				} else {
					cout << "\033[31;1m" << arg << "\033[m" << endl;
				}
			}
		}
	}
	
	/*
	//cout << "\033[5;31;1m"; /* set green on black and blinking */
	/* notes: the first parm: 5 tells it to blink... the second parm: 32 tells it green text... the third parm: 40 tells it black background */
	//cout << "U IZ N00b!! LOLZ!!!";
	//cout << "\033[m" << endl; /* stop blinking attribute from further text */
	//return 0;
	// */
}