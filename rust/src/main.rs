
#[script_macro::run_script_on(r##"
let output = item;
output += `fn fizzbuzz(n: u32) -> &'static str {match n {`;
for x in 1..101 {
    let fb = "";
    if x % 3 == 0 && x % 5 == 0 {
        fb = "FizzBuzz";
    } else if x % 3 == 0 {
        fb = "Fizz";
    } else if x % 5 == 0 {
        fb = "Buzz";
    } else {
        fb = x;
    }
    output += `
${x} => "${fb}",
`;
}
output += `_ => "",
}
}
`;
return output;
"##)]

fn main() {
    for i in 1..101 {
        println!("{}", fizzbuzz(i));
    }
}
