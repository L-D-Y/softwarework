# 1.基本情况
本项目依赖于easyx，核心内容是图层的叠加绘制，为了简化代码逻辑，不同功能的代码之间在满足条件的前提下~~使用goto语句进行跳转，虽然不优雅但着实有用。~~，通过对两个全局变量的更新和维护，使用循环和条件语句进行页面之间的跳转，比起goto语句更易于维护。


主要图像处理技术为双缓冲绘图机制，这也是贯穿整个项目的关键，在每一个需要进行绘图的地方一定要进行flush，将内存中的图像输出，不然程序会卡顿，在每一次刷新之后使用cleardevice（）清空缓冲区，~~可能会降低程序执行效率~~。


不知道是技术原因还是个人水平不足，代码在运行时有一定的延迟，在优化资源加载相关代码后有些许改善，但并不明显，~~能力有限，无法解决~~。


个人习惯将多个触发条件相同的函数归总到一个函数中，例如源.cpp中的begin（）函数，这样简化了代码逻辑，减少了代码量，但不利于优化，将一些函数搬到另外的头文件中，便于主函数所在页面的维护。


# 2.代码逻辑
所有可以进行互动的地方都进行了提示，鼠标悬停会有相对应的动态变化，通过监测鼠标左键和键盘输入实现对于资源的调度。


通过三个int变量监控鼠标事件，一个char变量监控键盘事件，能够监控的时候包括鼠标悬停，左键单击，键盘输入esc，三个全局变量需要维护。

使用mode全局变量来确定页面，分别加载出不同的页面


在程序运行时会创建一个player类的对象，所有的玩家行为都会对这个对象造成影响。


数值判定是通过计算君臣使佐不同的权重进行计算，从1000到1。
## 2.1 关卡代码基本结构
通过点击药材进行开药，依次点击有不同的权重，通过token之间的计算对比对应情况的token进行分数的控制和评语的输出。
## 2.2 药材采集页面
通过进行点击判定，增加player::myassets中存储的Medicine对象的num来对药材数量进行控制，~~本次更新已完成~~。
# 3.文件结构
~~在文件中，test.cpp，sup.h，sup.cpp三个文件不在最后输出的规划中，其作用是开发中函数的测试。~~已删除。
Draw相关文件主要是进行程序主要内容的绘制。
usingClass相关文件主要对使用到的类进行定义。

