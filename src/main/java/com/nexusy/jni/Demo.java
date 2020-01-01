package com.nexusy.jni;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.List;

/**
 * @author lanhuidong
 * @since 2019-12-30
 */
public class Demo {

    public static void main(String[] args) {
        System.loadLibrary("demo");
        JniService jniService = new JniService();
        jniService.init();

        System.out.println(jniService.square(10));

        System.out.println(jniService.sum(new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9}));

        File file = new File(args[0]);
        ByteBuffer buf = ByteBuffer.allocateDirect((int) file.length());
        try (InputStream is = new FileInputStream(file)) {
            byte[] tmp = new byte[(int) file.length()];
            int n = is.read(tmp);
            buf.put(tmp, 0, n);
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println(jniService.getSuffix(buf));

        Person p1 = new Person();
        p1.setName("java");
        Person p2 = new Person();
        p2.setName("jvm");
        List<Person> persons = List.of(p1, p2);
        jniService.parse(persons);
        persons.forEach(System.out::println);

        jniService.uninit();
    }

}
