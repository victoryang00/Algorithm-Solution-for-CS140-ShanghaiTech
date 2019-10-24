import java.util.Stack;

/**
 * Created by april on 2018/8/25. ������3���ˣ����ǵ���߷ֱ��� 2 3
 * 1����һ���˿������κ��ˣ��ڶ����˿��Կ���1�ˣ���������Ҳ���Կ���1�ˣ������ܺ�Ϊ2 ����ʹ�õ���ջ
 */
public class KuaiShou {

    public static int Count(int[] arr) {
        if (arr == null || arr.length == 0) {
            return 0;
        }
        Stack<Integer> stack = new Stack<>();
        stack.push(arr[0]);
        int count = 0;
        for (int i = 1; i < arr.length; i++) {

            if (arr[i] < stack.peek()) {// ��ջ��Ԫ��С�Ĳ�ѹջ������
                stack.push(arr[i]);
                count++;
            } else {
                while (!stack.isEmpty()) {
                    if (arr[i] >= stack.peek()) {// �����ջ��Ԫ�ش��򵯳�ջ��Ԫ�أ�ֱ��������ջ��Ԫ��С
                        stack.pop();
                        count++;
                    } else {
                        break;
                    }
                }
                if (!stack.isEmpty()) {
                    count++;
                }
                stack.push(arr[i]);// �ѵ�ǰ��ֵѹ��ջ����Ҫ��֮�ȽϺ����ֵ
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[] arr1 = new int[] { 2, 3, 1 };
        System.out.println(Count(arr1));
        int[] arr2 = new int[] { 4, 5, 6, 1, 2, 3, 5 };
        System.out.println(Count(arr2));
        int[] arr3 = new int[] { 3, 2, 1, 6, 3, 2, 1, 5 };
        System.out.println(Count(arr3));
    }
}