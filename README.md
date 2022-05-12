# ak-8ms

8ms for AK 37E

# 编译

```
make
```

可执行文件位于bin/qmsd-demo

# 测试
将qmsd-demo通过网口上传到板子（tftp或者scp），增加可执行权限，并运行。例如

```
cd /tmp
tftp -g 192.168.1.111 -r qmsd-demo
chmod +x qmsd-demo
./qmsd-demo
```

如果缺少相关库，请将extra/lib/下面的库拷贝的板子上