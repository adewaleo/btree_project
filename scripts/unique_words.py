import sys
import string


def remove_punctuation(s):
    return "".join([char for char in s if char not in (string.punctuation+string.whitespace)])

if __name__ == "__main__":
    file_name = sys.argv[1]

    try:
        in_file = open(file_name)
    except:
        print("Error opening {}".format(file_name))

    out_file = open("unique_out_" + file_name, 'w')

    unique_words = set()

    for line in in_file:
        words = line.split()
        for word in words:
            word = remove_punctuation(word)
            if len(word) > 8:
                continue
            if not word:
                continue
            word = word.lower()
            if word not in unique_words:
                unique_words.add(word)


    in_file.close()

    count_word = {}

    for word in unique_words:
        out_file.write(word+"\n")

    out_file.close()
