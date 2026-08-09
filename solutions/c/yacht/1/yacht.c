#include "yacht.h"
int score(dice_t dice, category_t category){
    int scor = 0;
    int val;
    if (category < ONES || category > YACHT)
        return 0;

    switch (category)
    {
        case ONES:
            for (int i = 0; i < 5; i++)
                if (dice.faces[i] == 1)
                    scor += 1;
            break;

        case TWOS:
            for (int i = 0; i < 5; i++)
                if (dice.faces[i] == 2)
                    scor += 2;
            break;

        case THREES:
            for (int i = 0; i < 5; i++)
                if (dice.faces[i] == 3)
                    scor += 3;
            break;

        case FOURS:
            for (int i = 0; i < 5; i++)
                if (dice.faces[i] == 4)
                    scor += 4;
            break;

        case FIVES:
            for (int i = 0; i < 5; i++)
                if (dice.faces[i] == 5)
                    scor += 5;
            break;

        case SIXES:
            for (int i = 0; i < 5; i++)
                if (dice.faces[i] == 6)
                    scor += 6;
            break;

        case FULL_HOUSE:
        {
            int count[7] = {0};
            int three = 0;
            int two = 0;
            for (int i = 0; i < 5; i++)
                count[dice.faces[i]]++;
            for (int i = 1; i <= 6; i++)
            {
                if (count[i] == 3)
                    three++;
                if (count[i] == 2)
                    two++;
            }
            if (three == 1 && two == 1)
            {
                for (int i = 0; i < 5; i++)
                    scor += dice.faces[i];
            }
            break;
        }

        case FOUR_OF_A_KIND:
        {
            int count[7] = {0};
            for (int i = 0; i < 5; i++)
                count[dice.faces[i]]++;
            for (int i = 1; i <= 6; i++)
            {
                if (count[i] >= 4){
                    scor = 4 * i;
                    break;
                }
            }
            break;
        }

        case LITTLE_STRAIGHT:
        {
            int count[7] = {0};
            for (int i = 0; i < 5; i++)
                count[dice.faces[i]]++;
            for (int i = 1; i <= 5; i++)
            {
                if (count[i] != 1)
                    return 0;
            }
            scor = 30;
            break;
        }

        case BIG_STRAIGHT:
        {
            int count[7] = {0};
            for (int i = 0; i < 5; i++)
                count[dice.faces[i]]++;
            for (int i = 2; i <= 6; i++)
            {
                if (count[i] != 1)
                    return 0;
            }
            scor = 30;
            break;
        }

        case CHOICE:
            for (int i = 0; i < 5; i++)
                scor += dice.faces[i];
            break;

        case YACHT:
            val = dice.faces[0];
            for (int i = 1; i < 5; i++)
            {
                if (dice.faces[i] != val)
                    return 0;
            }
            scor = 50;
            break;
        default:
            return 0;
    }
    return scor;
}

