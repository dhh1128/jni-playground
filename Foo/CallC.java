package Foo;

public class CallC
{
  public native int intMethod(int n);
  public native boolean booleanMethod(boolean bool);
  public native String stringMethod(String text);
  public native int intArrayMethod(int[] intArray);

  public static void main(String[] args)
  {
    System.loadLibrary("callc");
    CallC callc = new CallC();
    int     square = callc.intMethod(5);
    boolean bool   = callc.booleanMethod(true);
    String  text   = callc.stringMethod("JAVA");
    int     sum    = callc.intArrayMethod(
                        new int[]{1,1,2,3,5,8,13} );

    System.out.println("intMethod: " + square);
    System.out.println("booleanMethod: " + bool);
    System.out.println("stringMethod: " + text);
    System.out.println("intArrayMethod: " + sum);
  }
}
