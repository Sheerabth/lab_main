def print_guessing_word(guessing_word:list):
    for letter in guessing_word:
        if letter: print(letter, ' ', end="")
        else: print('_ ', end="")

def check_word(actual_word:str, guessing_word:list):
    guessing_word = ''.join(guessing_word)
    if guessing_word == actual_word:
        return True
    return False

def check_letter(acutual_word:str, guessed_letters:set, guessing_word:list, guessing_letter:str):
    if not guessing_letter:
        return -1
    elif guessing_letter in guessed_letters:
        return
    else:
        guessed_letters.add(guessing_letter)
        if guessing_letter in acutual_word:
            for i in range(len(acutual_word)):
                if acutual_word[i] == guessing_letter:
                    guessing_word[i] = guessing_letter
            return 1
        else:
            return 0

def play_hangman(actual_word:str, number_of_guesses:int):
    print("Welcome to Hangman!")
    guessed_letters = set()
    guessing_word = ['_']*len(actual_word)
    while (not check_word(actual_word, guessing_word) and number_of_guesses):
        print_guessing_word(guessing_word)
        guessing_letter = input("\tGuess your letter: ")
        option = check_letter(actual_word, guessed_letters, guessing_word, guessing_letter)
        if option == -1:
            print("Please guess a letter")
        elif option == 1:
            print("Your guess is correct!")
        else:
            number_of_guesses -= 1
            if option == 0:
                print("Your guess is incorrect")
            else:
                print("You already guessed this letter")
            print("Number of guesses remaining:", number_of_guesses)
    if(check_word(actual_word, guessing_word)):
        print("You won :) The word was", actual_word)
    else:
        print("You lost :( The word is", actual_word)

if __name__ == "__main__":
    word = "evaporate"
    no_of_guesses = 5
    play_hangman(word, no_of_guesses)
