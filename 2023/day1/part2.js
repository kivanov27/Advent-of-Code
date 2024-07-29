const fs = require('fs');
const readline = require('readline');

const path = './input.txt';
const fileStream = fs.createReadStream(path);

const rl = readline.createInterface({
    input: fileStream,
    crlfDelay: Infinity
});

const numberWords = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine'];
const wordToDigit = { zero: '0', one: '1', two: '2', three: '3', four: '4', five: '5', six: '6', seven: '7', eight: '8', nine: '9' };

let sum = 0

rl.on('line', line => {
    let first = null, last = null;

    for (let i = 0; i < line.length; i++) {
        if (/[0-9]/.test(line[i])) {
            if (!first) {
                first = line[i];
            }
            last = line[i];
        }

        for (let word of numberWords) {
            if (line.slice(i, i + word.length).toLowerCase() === word) {
                if (!first) {
                    first = wordToDigit[word];
                }
                last = wordToDigit[word];
            }
        }
    }

    if (!last) {
        last = first;
    }

    console.log(`first ${first}, last ${last}`);

    if (first && last) {
        const two_digit_num = first + last;
        sum += Number(two_digit_num);
        console.log(`line: ${line}, num: ${two_digit_num}, sum: ${sum}`);
    }
    else {
        console.log(`line: ${line}, num: ${null}, sum: ${sum}`);
    }

})

rl.on('close', () => {
    console.log(`Total sum: ${sum}`);
})
