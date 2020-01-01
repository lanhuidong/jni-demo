# jni-demo
1. 编写Java类, 定义native方法, 如: com.nexusy.jni.JniService.java

2. 创建C/C++ 头文件, 进入到JniService.java所在目录

   Java 9及之前版本: 

   ```shell
   javah . JniService
   ```

   Java 10及之后版本: 

   ```shell
   javac -h . JniService
   ```

   

3. 编写C/C++代码

4. 将C/C++代码编译为动态库

   macOS:

   ```shell
   clang -Wall -I$JAVA_HOME/include/ -I$JAVA_HOME/include/darwin/ -L. -lxxx -shared -undefined dynamic_lookup com_nexusy_jni_JniService.c -o libdemo.jnilib
   ```

   Linux:

   ```shell
   gcc -Wall -D jni_log -shared -fPIC -I$JAVA_HOME/include -I$JAVA_HOME/include/linux -L. -lxxx com_nexusy_jni_JniService.c -o libdemo.so
   ```

5. 运行java Demo

   ```shell
   export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
   java -Djava.library.path=. Demo
   ```

   

### 参考资料：

[http://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/jniTOC.html](http://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/jniTOC.html)

[https://www.ibm.com/developerworks/java/tutorials/j-jni/j-jni.html](https://www.ibm.com/developerworks/java/tutorials/j-jni/j-jni.html)