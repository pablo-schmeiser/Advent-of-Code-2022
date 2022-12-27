import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

public final class Main {
    private static final String C_USERS_PABLO_ONE_DRIVE_DESKTOP_ADVENT_OF_CODE_2022_DAY_5_SOLUTION_SRC_INPUT_TXT =
        "C:/Users/pablo/OneDrive/Desktop/Advent-of-Code-2022/Day 5/solution/src/input.txt";
    private static final char SPACE_CHAR = ' ';

    private Main() {
        //Utility class
    }

    private static void solutionOne() throws IOException {
        List<Stack<String>> buildingQueueList = new ArrayList<>();
        List<Stack<String>> stackList = new ArrayList<>();
        for (int i = 0; i < 9; i++) {
            buildingQueueList.add(new Stack<>());
            stackList.add(new Stack<>());
        }

        File file = new File(C_USERS_PABLO_ONE_DRIVE_DESKTOP_ADVENT_OF_CODE_2022_DAY_5_SOLUTION_SRC_INPUT_TXT);
        FileReader fr = new FileReader(file);
        BufferedReader br = new BufferedReader(fr);
        String line;
        boolean first = true;

        while((line = br.readLine()) != null){
            if (!line.isEmpty() && first) {
                for (int i = 0; i < line.length(); i++) {
                    if (line.charAt(i) != SPACE_CHAR && (i - 1) % 4 == 0) {
                        buildingQueueList.get((i - 1) / 4).push(String.valueOf(line.charAt(i)));
                    }
                }
            } else if (line.isEmpty()) {
                first = false;
                for (int i = 0; i < 9; i++) {
                    buildingQueueList.get(i).pop();
                    Collections.reverse(buildingQueueList.get(i));
                    stackList.get(i).addAll(buildingQueueList.get(i));
                }
            } else {
                int[] commandSpecs = Arrays.stream(line.split(" "))
                    .filter(s -> s.matches("\\d+"))
                    .mapToInt(Integer::parseInt).toArray();
                for (int i = 0; i < commandSpecs[0]; i++) {
                    stackList.get(commandSpecs[2] - 1).push(stackList.get(commandSpecs[1] - 1).pop());
                }
            }
        }
        br.close();
        fr.close();

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 9; i++) {
            sb.append(stackList.get(i).pop());
        }
        System.out.println(sb);
    }

    private static void solutionTwo() throws IOException {
        List<Stack<String>> buildingQueueList = new ArrayList<>();
        List<Stack<String>> stackList = new ArrayList<>();
        for (int i = 0; i < 9; i++) {
            buildingQueueList.add(new Stack<>());
            stackList.add(new Stack<>());
        }

        String fileName = C_USERS_PABLO_ONE_DRIVE_DESKTOP_ADVENT_OF_CODE_2022_DAY_5_SOLUTION_SRC_INPUT_TXT;
        File file = new File(fileName);
        FileReader fr = new FileReader(file);
        BufferedReader br = new BufferedReader(fr);
        String line;
        boolean first = true;

        while((line = br.readLine()) != null){
            if (!line.isEmpty() && first) {
                for (int i = 0; i < line.length(); i++) {
                    if (line.charAt(i) != SPACE_CHAR && (i - 1) % 4 == 0) {
                        buildingQueueList.get((i - 1) / 4).push(String.valueOf(line.charAt(i)));
                    }
                }
            } else if (line.isEmpty()) {
                first = false;
                for (int i = 0; i < 9; i++) {
                    buildingQueueList.get(i).pop();
                    Collections.reverse(buildingQueueList.get(i));
                    stackList.get(i).addAll(buildingQueueList.get(i));
                }
            } else {
                int[] commandSpecs = Arrays.stream(line.split(" "))
                    .filter(s -> s.matches("\\d+"))
                    .mapToInt(Integer::parseInt).toArray();
                Stack<String> inBetweenStack = new Stack<>();
                for (int i = 0; i < commandSpecs[0]; i++) {
                    inBetweenStack.push(stackList.get(commandSpecs[1] - 1).pop());
                }
                for (int i = 0; i < commandSpecs[0]; i++) {
                    stackList.get(commandSpecs[2] - 1).push(inBetweenStack.pop());
                }
            }
        }
        br.close();
        fr.close();

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 9; i++) {
            sb.append(stackList.get(i).pop());
        }
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException {
        solutionOne();
        solutionTwo();
    }
}
