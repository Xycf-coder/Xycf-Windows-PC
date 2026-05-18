/*
*Windows 电脑工具箱(Beta 1.0) - Windows PC Toolbox(Beta 1.0)
*作者:xycf(六年级小学生, 正在自学 C/C++)
*功能:扫盘 ,强制重启 ,强制关机 ,本机信息, 控制台颜色
*
*Author:xycf(6th-grade student, self-learning C/C++)
*Features: Scan Disk, Force Restart, Force Shutdown, System Info, Console Color
*/

#include<iostream>
#include<string>
#include<windows.h>
/*
头文件区
Header Files
*/

int choose_language();
int chong_qi();
int du_miao();
int guan_ji();
int sao_pan();
int guan_yu_ben_ji();
int tiao_se();
/*
*函数声明
*Function Declarations
*/

/*
*全局语言标志: 0 = 中文, 1 = 英文
*Global language flag: 0 = Chinese, 1 = English
*/
int g_language = 0;

// ==================== 主函数 ====================
/*
* 主函数 - 显示主菜单并根据用户选择调用对应功能
* Main - Displays the main menu and dispatches to selected function
*/
int main(){
	std::ios::sync_with_stdio(false);
	choose_language();
	while(1){
		system("cls");
		if(g_language == 0){
			std::cout << "====================欢迎来到由xycf开发的Windows 电脑工具箱(Beta 1.0)====================\n";
			std::cout << "如有改进的建议, 可发送电子邮件至15334014225@163.com";
			std::cout << "请问您需要以下那种服务?" << "\n";
			std::cout << "1. 扫盘服务" << "\n" << "2. 强制重启" << "\n" << "3. 强制关机" << "\n" << "4. 本机信息" << "\n" << "5. 调色" << "\n" << "6. 退出" << "\n";
		}
		else{
			std::cout << "====================Welcome to Windows PC Toolbox (Beta 1.0) by xycf====================\n";
			std::cout << "For suggestions, please email 15334014225@163.com";
			std::cout << "Which service do you need?" << "\n";
			std::cout << "1. Scan Disk" << "\n" << "2. Force Restart" << "\n" << "3. Force Shutdown" << "\n" << "4. System Info" << "\n" << "5. Change Color" << "\n" << "6. Exit" << "\n";
		}
		int number;
		std::cin >> number;
		if(std::cin.fail()){
			std::cin.clear();         
			std::cin.ignore(100,'\n');  
			std::cout << (g_language == 0 ? "请输入数字！\n" : "Please enter a number!\n");
			system("pause");
			continue;         
		}
		switch(number){
			case 1:
				sao_pan();
				break;
			case 2:
				chong_qi();
				break;
			case 3:
				guan_ji();
				break;
			case 4:
				guan_yu_ben_ji();
				break;
			case 5:
				tiao_se();
				break;
			case 6:
				if(g_language == 0){
					std::cout << "感谢使用 Windows 电脑工具箱 Beta 1.0！\n";
					std::cout << "如有改进建议，欢迎发邮件至 1533401425@163.com\n";
					std::cout << "程序退出，再见！\n";	
				}
				else{
					std::cout << "Thank you for using Windows PC Toolbox Beta 1.0!\n";
					std::cout << "For suggestions: 1533401425@163.com\n";
					std::cout << "Exiting, goodbye!\n";
				}
			exit(0);
			default :
				std::cout << (g_language == 0 ? "输入错误" : "Invalid input");
		}	
		system("pause");
		std::cout << std::endl;
	}	
}
// ==================== 语言选择 ====================
/*
* 语言选择 - 让用户在程序开始时选择中文或英文界面
* Language Selection - Allows the user to choose between Chinese and English UI
*/
int choose_language(){
	std::cout << "请选择语言 / Please select language:\n";
	std::cout << "1. 中文\n";
	std::cout << "2. English\n";
	std::cout << "请输入选择 / Enter your choice: ";
	int choice;
	std::cin >> choice;
	
	if (choice == 2) {
		g_language = 1;
		std::cout << "Language set to English.\n" << std::endl;
	} else {
		g_language = 0;
		std::cout << "语言已设置为中文。\n" << std::endl;
	}
	system("pause");
	return 0;
}
/*
* 扫盘功能 - 使用 dir /s 命令列出所有文件
* Scan Disk - Uses 'dir /s' to list all files
*/
int sao_pan(){
	int term1;
	if(g_language == 0){
		std::cout << "您的电脑需要扫盘服务吗(扫盘请输入1, 否则输入0。)?" << "\n";	
	}
	else{
		std::cout << "Do you want to scan the disk(1 = Yes, 0 = No)?" << "\n";
	}
	std::cin >> term1;
	if(term1 == 1){
		if(g_language == 0){
			std::cout << "请输入在多少秒后进行扫盘" << "\n";
			du_miao();
			std::cout << "感谢使用。" << "\n";	
		}
		else{
			std::cout << "Enter the number of seconds before scanning starts:" << "\n";
			du_miao();
			std::cout << "Thank you. Starting scan...\n";
		}
		system("dir /s");
	}
	else{
		if(g_language == 0){
			std::cout << "感谢使用。" << "\n";	
		}
		else{
			std::cout << "Thank you.\n";
		}
	}
	return 0;
}
/*
* 强制重启 - 调用 shutdown /r /t 0 命令
* Force Restart - Calls 'shutdown /r /t 0'
*/
int chong_qi(){
	int term2;
	if(g_language == 0){
		std::cout << "您的电脑需要强制重启吗(重启请输入1, 否则输入0。)?" << "\n";	
	}
	else{
		std::cout << "Do you want to force restart? (1 = Yes, 0 = No)" << "\n";
	}
	std::cin >> term2;
	if(term2 == 1){
		if(g_language == 0){
			std::cout << "请输入在多少秒后进行强制重启" << "\n";
			du_miao();
			std::cout << "感谢使用。" << "\n";	
		}
		else{
			std::cout << "Enter seconds before restart:" << "\n";
			du_miao();
			std::cout << "Thank you. Restarting...\n";
		}
		system("shutdown /r /t 0");
	}
	else{
		if(g_language == 0){
			std::cout << "感谢使用。" << "\n";	
		}
		else{
			std::cout << "Thank you.\n";
		}
	}
	return 0;
}
/*
* 强制关机 - 调用 shutdown /s /t 0 命令
* Force Shutdown - Calls 'shutdown /s /t 0'
*/
int guan_ji(){
	int term3;
	if(g_language == 0){
		std::cout << "您的电脑需要强制关机吗(关机请输入1, 否则输入0。)?" << "\n";
	}
	else{
		std::cout << "Do you want to force shutdown? (1 = Yes, 0 = No)" << "\n";
	}
	std::cin >> term3;
	if(term3 == 1){
		if(g_language == 0){
			std::cout << "请输入在多少秒后进行强制关机" << "\n";
			du_miao();
			std::cout << "感谢使用。" << "\n";	
		}
		else{
			std::cout << "Enter seconds before shutdown:" << "\n";
			du_miao();
			std::cout << "Thank you. Shutting down...\n";
		}
		system("shutdown /s /t 0");
	}
	else{
		if(g_language == 0){
			std::cout << "感谢使用。" << "\n";	
		}
		else{
			std::cout << "Thank you.\n";
		}
	}
	return 0;
}
/*
* 本机信息 - 调用 systeminfo 命令
* System Info - Calls 'systeminfo'
*/
 int guan_yu_ben_ji(){
	int term4;
	if(g_language == 0){
		std::cout << "您需要本计算机的详细系统信息吗(需要请输入1, 否则输入0。)?" << "\n";
	}
	else{
		std::cout << "Do you need detailed system information? (1 = Yes, 0 = No)" << "\n";
	}
	std::cin >> term4;
	if(term4 == 1){
		if(g_language == 0){
			std::cout << "请输入在多少秒后显示信息" << "\n";
			du_miao();
			std::cout << "感谢使用。" << "\n";	
		}
		else{
			std::cout << "Enter seconds before displaying info:" << "\n";
			du_miao();
			std::cout << "Thank you.\n";
		}
		system("systeminfo");
	}
	else{
		if(g_language == 0){
			std::cout << "感谢使用。" << "\n";	
		}
		else{
			std::cout << "Thank you.\n";
		}
	}
	return 0;
}
/*
* 倒计时功能 - 用户输入秒数，每秒提醒一次，最后执行操作
* Countdown Timer - Waits for user-specified seconds before executing
*/
int du_miao(){
	int times;
	std::cin >> times;
	while(times > 0){
		if(g_language == 0){
			std::cout << "距离程序启动还有" << times << "秒" << std::endl;	
		}
		else{
			std::cout << times << " seconds remaining..." << std::endl;
		}
		times--;
		Sleep(1000);
	}
	return 0;
}
/*
* 调色功能 - 让用户输入十六进制颜色代码，改变控制台字体颜色
* Change Console Color - Asks for a hex color code and applies it
* 注意：目前仅支持输入一位字符改变字体颜色，两位字符的背景+前景色功能待修复
* Note: Currently only supports 1-digit input to change text color; 2-digit background+foreground support to be fixed
*/
int tiao_se(){
	int term5;
	if(g_language == 0){
		std::cout << "您需要改变控制台字体颜色吗(需要请输入1, 否则输入0。)?" << "\n";
	}
	else{
		std::cout << "Do you want to change the console color? (1 = Yes, 0 = No)" << "\n";
	}
	std::cin >> term5;
	if(term5 == 1){
		if(g_language == 0){
			std::cout << "请输入您想要的一位颜色代码" << "\n";
		}
		else{
			std::cout << "Please enter a 1-digit hex color code:" << "\n";
		}
		std::string color;
		std::cin >> color;
		system(("color " + color).c_str());
		if(g_language == 0){
			std::cout << "配色已修改。" << "\n";
			std::cout << "感谢使用。" << "\n";
		}
		else{
			std::cout << "Color changed." << "\n";
			std::cout << "Thank you." << "\n";
		}
	}
	else{
		if(g_language == 0){
			std::cout << "配色未修改。" << "\n";
			std::cout << "感谢使用。" << "\n";
		}
		else{
			std::cout << "Color not changed." << "\n";
			std::cout << "Thank you." << "\n";
		}
	}
	return 0;
}
