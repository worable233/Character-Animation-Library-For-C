#ifndef CALFC_H_INCLUDED // ✅ 如果没有定义这个宏...
#define CALFC_H_INCLUDED // ✅ ...就定义它，并编译以下内容
// 声明函数(初始化函数) // ✅ 内容放这里
void clean(void);
int loading(char *text,int times,float sleeptime);
int textbox(char *name,char *text,float sleeptime);
int loading_text(char *text,int times,float sleeptime);
#endif // ✅ 结束条件编译