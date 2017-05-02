public class Demo {
    
    private native int square(int i);

    private native boolean reverse(boolean b);

    private native String upper(String s);

    private native int sum(int[] array);

    public static void main(String[] args) {
        Demo demo = new Demo();
        System.loadLibrary("demo");
        System.out.println(demo.square(7));
        System.out.println(demo.reverse(false));
        System.out.println(demo.upper("jni"));
        System.out.println(demo.sum(new int[]{1, 2, 3, 4, 5}));
    }
}
