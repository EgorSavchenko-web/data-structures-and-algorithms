import java.util.*;

public class Scoreboard {

    public static List<String> fetchTopPlayers(List<String> data, int limit) {
        List<ScoreEntry> scoresList = new ArrayList<>();

        for (String record : data) {
            String[] elements = record.split(" ");
            String username = elements[0];
            int points = Integer.parseInt(elements[1]);
            scoresList.add(new ScoreEntry(username, points));
        }

        scoresList.sort((first, second) -> Integer.compare(second.points, first.points));

        List<String> topPlayers = new ArrayList<>();
        for (int index = 0; index < Math.min(limit, scoresList.size()); index++) {
            topPlayers.add(scoresList.get(index).username + " " + scoresList.get(index).points);
        }

        return topPlayers;
    }

    static class ScoreEntry {
        String username;
        int points;

        ScoreEntry(String username, int points) {
            this.username = username;
            this.points = points;
        }
    }

    public static void main(String[] args) {
        Scanner inputScanner = new Scanner(System.in);

        int totalEntries = inputScanner.nextInt();
        int maxEntries = inputScanner.nextInt();
        inputScanner.nextLine(); // Clear the buffer

        List<String> records = new ArrayList<>();

        for (int i = 0; i < totalEntries; i++) {
            records.add(inputScanner.nextLine());
        }

        List<String> topResults = fetchTopPlayers(records, maxEntries);

        for (String result : topResults) {
            System.out.println(result);
        }

        inputScanner.close();
    }
}