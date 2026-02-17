// 引入头文件
#include <stdio.h>
#include <unistd.h>
#include "CALFC.h" // 编译器会在当前目录找
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