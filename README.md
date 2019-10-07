# 《白话C++》代码

## 正确配置IDE的文件编码识别机制

代码均以Code::Blocks的工程进行组织，并在Windows写成。不少代码中含有汉字，典型的如代码中一些注释。为避免Code::Blocks打开源代码时，将汉字显示成乱码，请在Windows下对Code::Blocks作如下配置。

点击 Code::Blocks主菜单：“Setting” -> “Editor” 。然后按下图进行设置。

![Code::Blocks的文件编码识别设置](http://image.d2school.com/img/github/bhcpp/codeblocks_file_encoding_set_for_bhcpp.jpg)

## 目录组织说明

1. 第1层为章。比如：03-feeling-1 表示：第3章，《感受一》
2. 第2层为章节。比如：3.10.3-HelloOOVirtual 表示：第 3.10.3 小节。
3. 章节后如果还接有 -N，其中N为整数，表示该小节内相关代码的第N个教学演进版本（而非指该小节下的第几点）。比如：3.11.5-2-HelloOOEncapsulation。表示第3.11.5小节中，有关“封装应用示例” 代码的第2个演进版本。
