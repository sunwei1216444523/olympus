# olympus
Olympus is a lite routing engine for high-definition map. Inspired by Valhalla, so it named Olympus.

## 内存设计
考虑到英灵殿使用的是直接常驻内存，然后自己写一套管理方式，我们这里为了不直接自己手写一套管理方式，是否能考虑使用redis来管理tiles的加载？
数据的唤起是通过tileid,即使是Valhalla也是通过把id通过划分的方式，便于快速找到索引，然后加载到内存中。 

这样的好处就是也方便更新
