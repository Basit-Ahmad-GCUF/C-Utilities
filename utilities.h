#ifndef utilities_h
#define utilities_h

#include<iostream>
#include<chrono>
#include<thread>
#include<string>
#include<conio.h>

namespace color{
	// Reset Color
	inline const std::string reset   = "\033[0m";
	
    // Standard Colors
    inline const std::string black   = "\033[30m";
    inline const std::string blue    = "\033[34m";
    inline const std::string green   = "\033[32m";
    inline const std::string cyan    = "\033[36m";
    inline const std::string red     = "\033[31m";
    inline const std::string magenta = "\033[35m";
    inline const std::string yellow  = "\033[33m";
    inline const std::string white   = "\033[37m";
    
    // Bright Colors
    inline const std::string b_black   = "\033[90m";
    inline const std::string b_blue    = "\033[94m";
    inline const std::string b_green   = "\033[92m";
    inline const std::string b_cyan    = "\033[96m";
    inline const std::string b_red     = "\033[91m";
    inline const std::string b_magenta = "\033[95m";
    inline const std::string b_yellow  = "\033[93m";
    inline const std::string b_white   = "\033[97m";
    
}
namespace style{
	// Text Attributes
	inline const std::string bold      = "\033[1m";
    inline const std::string dim       = "\033[2m";
    inline const std::string italic    = "\033[3m";
    inline const std::string underline = "\033[4m";
    inline const std::string blink     = "\033[5m";
}

class sys{
	public:
		static void clearscreen(){
    		std::cout<<"\033[2J\033[H";
		}

		static void pause(){
    		std::cout<<"\n\t\t";
			_getch();
		}
		static void playspinner(int cycles, std::string msg){
            char vars[] = {'/', '-', '\\', '|', '-'};
            for (int i = 0; i < cycles; ++i) 
			{
                for (char c : vars) 		//Ranged Loop.
				{
                    std::cout << "\r [ " << c << " ] " << msg << "...";
                    std::cout.flush();
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
            }
            int total_length = 10 + msg.length();
            std::cout<<"\r";
            for(int i = 0 ; i<= total_length ; i++)
            	std::cout<<" ";
            std::cout<<"\r [\u2713] Done!"<<std::endl;
        }
        static void printdots(int count)
        {
        	for(int i = 0 ; i <= count ; i++)
        	{
        		std::cout<<".";
        		std::cout.flush();
        		std::this_thread::sleep_for(std::chrono::milliseconds(750));
			}
		}
		static void type_write(const std::string& message) 
		{
			int waiting_delay = 40;
		    for (char ch : message) {
		        std::cout << ch;
		        std::cout.flush();
		        std::this_thread::sleep_for(std::chrono::milliseconds(waiting_delay));
		    }
		}
		static void timer(int time, std::string message)
		{
			for(time ; time > 0 ; time--)
			{
				std::cout<< "\r" << message << " < " << time << " > Seconds....";
				std::cout.flush();
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
		}
		static std::string maskedinput() 
		{
            std::string msg = "";
            char ch;
            while ((ch = _getch()) != '\r') 
			{
                if (ch == '\b') 
				{
                    if (!msg.empty()) 
					{
                        msg.pop_back();
                        std::cout << "\b \b";
                    }
                } 
				else 
				{
                    msg += ch;
                    std::cout << "*";
                }
            }
            std::cout << "\n";
            return msg;
        }
    	static int getint(std::string message)
		{
        	int value = 0;
        	while(true)
			{
        		
        		std::cout<< message;
        		std::cin>> value;
        		if(std::cin.fail()) 
				{
        			std::cin.clear();
        			std::cin.ignore(1000,'\n');
        			std::cout<<color::red<<"\n\t\t\a[ERROR] Enter a Valid Integer value! Try Again."<<color::reset;
				}
				else
				{
					break;
				}	
			}
        	return value;
		}
		static double getfloat(std::string message)
		{
        	double value = 0.0;
        	while(true)
			{
        		
        		std::cout<< message;
        		std::cin>> value;
        		if(std::cin.fail()) 
				{
        			std::cin.clear();
        			std::cin.ignore(1000,'\n');
        			std::cout<<color::red<<"\n\t\t\a[ERROR] Enter a Valid Float Value! Try Again."<<color::reset;
				}
				else
				{
					break;
				}	
			}
        	return value;
		}
};

class design{
	public:
		static void line(int n, std::string s){
			for(int i = 0 ; i < n ; i++ ){
				std::cout<<s;
			}
		}
		static void draw_header(std::string message, std::string symbol){
			int space = 10, total_length = message.length() + (2*space);
			std::cout<<"\n\t\t\t++"; line(total_length , symbol);std::cout<<"++";
			std::cout<<"\n\t\t\t||"; for(int i=0 ; i<space ; i++) std::cout<<" "; std::cout<<message; for(int i=0 ; i<space ; i++) std::cout<<" "; std::cout<<"||";
			std::cout<<"\n\t\t\t++"; line(total_length , symbol);std::cout<<"++";
		}
};

#endif