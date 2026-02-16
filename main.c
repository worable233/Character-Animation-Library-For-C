// 引入头文件
#include <stdio.h>
#include <unistd.h>
// 声明函数
void clean(void);
int loading(char *text,int times,float sleeptime);
int textbox(char *name,char *text,float sleeptime);
int loading_text(char *text,int times,float sleeptime);
// 声明全局变量
const char *strings[] = {"|", "/", "—", "\\"}; // 加载动画放在这里了，\n换行为了美观
const int int_len = sizeof(strings) / sizeof(strings[0]);// 计算数组长度
// 主程序
int main(void) {
	loading_text("加载中...",10,0.2); // 这里可以修改文字内容动画显示秒数，默认10秒
	sleep(1);
	int number = loading("加载中...",10,0.1); // 这里可以修改文字内容动画显示秒数，默认10秒
	if (number == 0) { // 判断返回值
		printf("\r加载成功！");
		sleep(1);
		clean();
		number = textbox("DeepSeek","总结 ：这个错误通常在系统策略限制后台传输时发生，在企业环境中比较常见。",0.1); // 这里可以修改文字内容
		if (number == 0) { // 判断返回值
			return 0;
		} else {
			printf("\r输出失败！");
			return 2;
		}
	} else {
		printf("\r加载失败！");
		return 1;
	}
}
// 加载动画函数
int loading_text(char *text,int times,float sleeptime) {
	if (text == NULL) { // 判断空指针
		return 1;
	}
	sleeptime = sleeptime * 1000000; // 转换进制
	int TIME_plustime = 100 / times; // 计算每次增加的时间
	int TIME_nowtime = 0;
	for (int i = 0; i < times; i++) { // 伪计时
		clean();
		printf("\r%s %i%%",text, TIME_nowtime);  // \r 回到行首
		fflush(stdout);  // 立即刷新输出
		usleep(sleeptime); // 等待
		TIME_nowtime += TIME_plustime; // 增加时间
	}
	clean();
	return 0;
}
// 加载动画函数
int loading(char *text,int times,float sleeptime) {
	if (text == NULL) { // 判断空指针
		return 1;
	}
	sleeptime = sleeptime * 1000000; // 转换进制
	for (int i = 0; i < times; i++) { // 伪计时
		clean();
		printf("\r%s %s",text, strings[i % int_len]);  // \r 回到行首
		fflush(stdout);  // 立即刷新输出
		usleep(sleeptime); // 等待
	}
	clean();
	return 0;
}
// 对话框函数
int textbox(char *name,char *text,float sleeptime) {
	if (name == NULL || text == NULL) { // 判断空指针
		return 1;
	}
	sleeptime = sleeptime * 1000000; // 转换进制
	int string_len = strlen(text); // 计算长度
	printf("\r%s | ",name); // 输出昵称
	fflush(stdout);
	for(int n = 0; n < string_len; n++) {
		printf("%c",text[n]);  // 输出单个字符
		fflush(stdout);  // 立即刷新输出
		// 根据字符类型设置不同的延迟
		if (text[n] == ' ') {
			// 标点和空格处停顿时间加倍
			usleep(sleeptime * 1.5);
		} else {
			usleep(sleeptime);
		} // 模拟停顿
	}
	return 0;
}
// 清空当前行终端函数
void clean(void) {
	printf("\033[2K"); // \033[2K 清空当前行
}