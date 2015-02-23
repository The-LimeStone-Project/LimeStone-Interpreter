一、概述
========
TLSP(The LimeStone Project)，是以LSI(LimeStone Interpreter)为解释器的脚本化程序设计语言。使用基本的面向过程模型以及简单的文法，用户可以使用最简单的格式完整、快速的表达思想。
========
二、特性
========
1.简易的格式
2.轻量级的解释器
3.无冗余定义
4.快速编写代码
5.执行速度优化
6.接近自然语言的文法
========
三、基础文法
========
1.使用iolib.lsslib来进行输入/输出。该库已被默认集成于解释器中。
	-print(<string>) 进行输出。
	-input(<string>) 进行输入。
2.使用接近于自然语言的控制语句控制程序的流程。
	for i: first=1; last=5; step=2 :: <CODE> ,
	if i is true then <CODE> [else <CODE>],
	
3.使用function关键字来定义函数：待撰写
4.支持递归函数。
	foo();
========
四、解释器
========
LimeStone脚本文件(.lss)的解释器程序被命名为LSI。这个解释程序由Aurura小组开发/维护。
========
五、支持
========
LimeStone解释器程序(LSI)的支持与bug反馈可以发送至:support@aurura.net或联系QQ：466213748(项目负责人)
