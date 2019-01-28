# LCD1602_Driver_For_Raspberry_Pi
LCD1602 Driver For Raspberry Pi 3
<b>v0.0.2</b>

树莓派3b的Lcd1602驱动，基于wiringPi编写。<br/>

运行例子方法：</br>
1.确保你的树莓派已经安装 wiringPi</br>
2.连线</br>
VSS -> GND</br>
VDD -> VCC</br>
VO  -> 偏压信号</br>
RS  -> GPIO1</br>
RW  -> GPIO4</br>
E   -> GPIO5</br>
D   -> GPIO0</br>
D   -> GPIO2</br>
D   -> GPIO3</br>
D   -> GPIO21</br>
D   -> GPIO22</br>
D   -> GPIO23</br>
D   -> GPIO24</br>
D   -> GPIO25</br>
A   -> VCC</br>
K   -> GND</br>
3.切换到项目目录然后<code>g++ lcd1602.cpp example_tiny_clock.cpp -lwiringPi  && ./a.out</code></br>
4.完成</br>
<br/>
更新日志<br/>
<b>v0.0.2</b>:修复首次执行LCD1602::Write_String()函数时位置参数无效问题；加入屏幕滚动功能。<br/>
<br/>
<b>v0.0.1</b>:目前仅实现基础功能。<br/>
<br/>
<br/>
2019年1月28日17:51:32</br>
