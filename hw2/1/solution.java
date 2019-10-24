import java.util.Stack;

/**
 * Created by april on 2018/8/25. 比如有3个人，他们的身高分别是 2 3
 * 1。第一个人看不见任何人，第二个人可以看见1人，第三个人也可以看见1人，所以总和为2 考虑使用单调栈
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

            if (arr[i] < stack.peek()) {// 比栈顶元素小的才压栈并计数
                stack.push(arr[i]);
                count++;
            } else {
                while (!stack.isEmpty()) {
                    if (arr[i] >= stack.peek()) {// 如果比栈顶元素大则弹出栈顶元素，直到遇到比栈顶元素小
                        stack.pop();
                        count++;
                    } else {
                        break;
                    }
                }
                if (!stack.isEmpty()) {
                    count++;
                }
                stack.push(arr[i]);// 把当前的值压入栈，需要与之比较后面的值
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