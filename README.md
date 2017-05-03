# jni-demo
1. 编写Demo.java并编译生成Demo.class文件

2. 创建C/C++ 头文件，javah Demo

3. 编写C/C++代码

4. 将C/C++代码编译为动态库

   macOS:

   ```shell
   clang -I/Library/Java/JavaVirtualMachines/jdk1.8.0_40.jdk/Contents/Home/include/ -I/Library/Java/JavaVirtualMachines/jdk1.8.0_40.jdk/Contents/Home/include/darwin/ -shared -undefined dynamic_lookup -o libdemo.jnilib Demo.c
   ```

5. 运行java Demo

   ​

### 参考资料：

[http://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/jniTOC.html](http://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/jniTOC.html)

[https://www.ibm.com/developerworks/java/tutorials/j-jni/j-jni.html](https://www.ibm.com/developerworks/java/tutorials/j-jni/j-jni.html)