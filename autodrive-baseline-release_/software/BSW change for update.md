BSW change

PPnC_CR2003b_dev01a版本
    1.修改MPFU_TrafficSign结构体使其跟应用层和ATOM一致
    2.杭州公交项目CAN2/3改成CAN4/5，并根据应用层结构体进行了存储结构体名称变更
    3.增加KcCOMM_VehicleCANbusConfig = 7这个新模式
    4.增加data logging trigger传给ATOM的新功能
    5.增加HMI signal传给ATOM的新功能

PPnC_CR2003b_dev03a版本
    基于应用层更新LCCS模块，修复lcws模块Inca标定量不能使用的问题。

PPnC_CR2003b_dev05a版本
    基于应用层更新LCCS/DCSN/LDWS模块，删除底层软件297传给atom的不合理逻辑

PPnC_CR2003b_dev07b版本
    基于应用层更新LCWS模块的集成

PPnC_CR2003b_dev12c
   加入了AEBD模块，底层新加novatel由297解析并转发的功能

PPnC_CR2003b_dev12d
   基于最新应用层软件更新，底层加入can是否读入的标志位，等待需求明确用于后续开发

PPnC_CR2004b_dev01a
   基于最新PPnc_CR2004b更新，应用于测试，配置为6时CAN4发送有问题

PPnC_CR2004b_dev02a
   修复CAN4发送其中一路不正常的BUG，更新LCWS模块

PPnC_CR2004b_dev03b
   添加左右转向灯拨杆信号传给应用层

PPnC_CR2004b_dev07c
   加入boot功能，可以使用INCA刷入

PPnC_CR2004b_dev09d
   修复novatel在某些特定地点会出现计算数值错误的bug

PPnC_CR2004b_dev13e_JAC2
   对2号车增加地平线相机的解析和转发到atom功能,CAN0波特率为1M

PPnC_CR2004b_dev15e
   增加了INCA一个20ms观测周期，里面可以放80个观测量

PPnC_CR2004b_dev16f
   1.对egmotion的接收初步做了粘包拼包处理，更稳固安全的校验方式需和成哥讨论，并更改些接口
   2.卡车PGN为F0A2的CAN 的第五个字节的前6bit改为0

PPnC_CR2004b_dev18g
   修改编译选项，enum类型在两个版本里统一改成short enum

PPnC_CR2004b_dev23g
   1.增加了故障诊断接收功能（未开启）
   2.增加了UDP通讯的诊断，加入checksum和rolling_counter

PPnc_CR2005b_dev2b
   1.在故障诊断功能基础上，增加了声光报警器
   2.修复了诺瓦太utc_time的最小单位输出

PPnc_CR2005b_dev7c_JAC2
   1.根据算法要求，更改了地平线相机解析的部分内容
   2.增加了vehicle的几个变量的传输

PPnc_CR2005b_dev8d_JAC2
   修复地平线相机和novatelbug，对地平线相机数据接收相关指针的区域进行了限制，防止由于接收到地平线相机偶尔的错误帧导致的对novatel状态的修改

PPnc_CR2005b_dev09e
   将KcCOMM_VehicleCANbusConfig = 3时原本CAN1的车身CAN改到CAN2上

PPnc_CR2005b_dev09f
   将地平线相机解析转发程序移植到CAN1上，当将KcCOMM_VehicleCANbusConfig = 1或2的时候有效

PPnc_CR2005b_dev11g
   增加应用层需要的两种报警模式按不同频率的声音报警

PPnc_CR2005b_dev13h
   这个版本开了UDP诊断以及ATOM诊断信息的接收

PPnc_CR2005b_dev15h
   加入了radar410的接收和解析工作

PPnc_CR2006b_dev01b
   使用我们自己写的makefile编译出的版本