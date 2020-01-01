package com.nexusy.jni;

import java.nio.ByteBuffer;
import java.util.List;

/**
 * @author lanhuidong
 * @since 2019-12-30
 */
public class JniService {

    /**
     * 初始化
     */
    public native void init();

    /**
     * 反初始化
     */
    public native void uninit();

    /**
     * 求指定数字的平方
     *
     * @param num 数字
     * @return 指定数字的平方
     */
    public native int square(int num);

    /**
     * 求数组的和
     *
     * @param array 数组
     * @return 数组和
     */
    public native int sum(int[] array);

    /**
     * 根据魔数获取文件扩展名
     *
     * @param data 文件
     * @return 扩张名
     */
    public native String getSuffix(ByteBuffer data);

    public native void parse(List<Person> persons);

}
