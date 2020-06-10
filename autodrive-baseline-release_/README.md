297控制软件的中间版本管理：
1.	继续使用autodrive_baseline_release的gitlab工程作为APP和BSW的交互媒介
2.	最新需要编译的各模块代码会首先在PPnC组内协调集中，统一上传到dev分支/code目录下，并有相应的release_note文件说明dev版本和更新内容
3.	BSW同事收到编译请求后，在dev分支/code目录下统一下载所有代码进行编译，根据说明文件中的版本对软件进行命名，收到请求后原则上在半个工作日内提供软件，特殊情况可随时沟通灵活解决。
4.	编译完后BSW同事将可执行文件（APP+OS）放入dev分支/software文件夹
5.	baseline软件发布冻结后统一拉出相应baseline分支作为存档

软件版本号命名：

PPnC_CR1912b_released             // baseline 1912b的release版本号

PPnC_CR2003b_dev01                // baseline 2003b的中间开发版本号

PPnC_CR2003b_dev02

PPnC_CR2003b_dev03a               // a,b后缀代表BSW软件在同一APP软件版本内的更新

PPnC_CR2003b_dev03b

PPnC_CR2003b_dev04

PPnC_CR2003b_released             // baseline 2003b的release版本号

