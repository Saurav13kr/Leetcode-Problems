class Solution {
    private static final int WORD_LENGTH = 6;

    public void findSecretWord(String[] words, Master master) {
        int numWords = words.length;
        boolean[] eliminate = new boolean[numWords];
        int index = 0;
        int output = master.guess(words[index]), lastGuess, total;

        while(output != WORD_LENGTH) {
            lastGuess = index;
            eliminate[lastGuess] = true;

            for(int i=0; i<numWords; i++) {
                if (eliminate[i]) {
                    continue;
                }

                total = 0;
                for(int j=0; j<WORD_LENGTH; j++) {
                    if (words[lastGuess].charAt(j) == words[i].charAt(j)) {
                        total++;
                    }
                }

                if (total != output) {
                    eliminate[i] = true;
                } else {
                    index = i;
                }
            }

            output = master.guess(words[index]);
        }
    }
}