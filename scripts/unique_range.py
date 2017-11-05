import sys
import string


def remove_punctuation(s):
    return "".join([char for char in s if char not in (string.punctuation+string.whitespace)])

if __name__ == "__main__":
    if (len(sys.argv) != 4):
        print ("usage: python unique_range.py file_name lower_key upper_key ")
        exit(1)

    file_name = sys.argv[1]
    lower = sys.argv[2]
    upper = sys.argv[3]


    try:
        in_file = open(file_name)
    except:
        print("Error opening {}".format(file_name))

    unique_words = set()

    for word in in_file:
        unique_words.add(word.strip())

    in_file.close()


    for word in sorted(list(unique_words)):
        if lower <= word and word <= upper:
            print(word)
