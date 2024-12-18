# 1.基本情况
本项目依赖于easyx，核心内容是图层的叠加绘制，为了简化代码逻辑，不同功能的代码之间在满足条件的前提下使用goto语句进行跳转，虽然不优雅但着实有用。


主要图像处理技术为双缓冲绘图机制，这也是贯穿整个项目的关键，在每一个需要进行绘图的地方一定要进行flush，将内存中的图像输出，不然程序会卡顿。


不知道是技术原因还是个人水平不足，代码在运行时有一定的延迟，在优化资源加载相关代码后有些许改善，但并不明显。


个人习惯将多个触发条件相同的函数归总到一个函数中，例如源.cpp中的begin（）函数，这样简化了代码逻辑，减少了代码量，但不利于优化。


# 2.代码逻辑
所有可以进行互动的地方都进行了提示，鼠标悬停会有相对应的动态变化。


通过三个int变量监控鼠标事件，一个char变量监控键盘事件，能够监控的时候包括鼠标悬停，左键单击，键盘输入esc。


在程序运行时会创建一个player类的对象，所有的玩家行为都会对这个对象造成影响。


数值判定是通过计算君臣使佐不同的权重进行计算，从1000到1（该部分待完善）。
## 2.1 关卡代码基本结构
（待完善）

# 3.文件结构
在文件中，test.cpp，sup.h，sup.cpp三个文件不在最后输出的规划中，其作用是开发中函数的测试。
Draw相关文件主要是进行程序主要内容的绘制。
usingClass相关文件主要对使用到的类进行定义。
Setting相关文件是针对“设置”功能创建的文件（未完善）。

