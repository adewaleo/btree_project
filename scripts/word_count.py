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

    out_file = open("out_" + file_name, 'w')

    out_file_sorted = open("sort_out_" + file_name, 'w' )

    word_count = {}

    for line in in_file:
        words = line.split()
        for word in words:
            word = remove_punctuation(word)
            if not word:
                continue
            if word in word_count:
                word_count[word] += 1
            else:
                word_count[word] = 1

    in_file.close()

    count_word = {}

    for word, count in word_count.items():
        out_file.write(word+" "+str(count)+"\n")
        count_word[count] = word

    for count in sorted(count_word.keys()):
        out_file_sorted.write(str(count)+" "+count_word[count]+"\n")


    out_file.close()
    out_file_sorted.close()
