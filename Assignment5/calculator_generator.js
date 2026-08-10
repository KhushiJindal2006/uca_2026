function* calc(initialValue) {

 
    if (typeof initialValue !== "number" || !Number.isFinite(initialValue)) {
        throw new Error("Initial value must be a valid number");
    }

    let result = initialValue;

    while (true) {

        
        const input = yield result;

     
        if (!input || typeof input !== "object") {
            console.log("Invalid input");
            continue;
        }

       
        const validOperations = [
            "add",
            "subtract",
            "multiply",
            "divide"
        ];

       
        if (!validOperations.includes(input.operation)) {
            console.log("Invalid operation");
            continue;
        }

       
        if (
            typeof input.value !== "number" ||
            !Number.isFinite(input.value)
        ) {
            console.log("Invalid input");
            continue;
        }

      
        if (input.operation === "divide" && input.value === 0) {
            console.log("Error: Cannot divide by zero");
            continue;
        }

        
        switch (input.operation) {

            case "add":
                result += input.value;
                break;

            case "subtract":
                result -= input.value;
                break;

            case "multiply":
                result *= input.value;
                break;

            case "divide":
                result /= input.value;
                break;
        }
    }
}



const calculator = calc(50);


console.log(calculator.next().value);

console.log(
    calculator.next({
        operation: "add",
        value: 30
    }).value
);

console.log(
    calculator.next({
        operation: "multiply",
        value: 2
    }).value
);

console.log(
    calculator.next({
        operation: "add",
        value: "30"
    }).value
);

console.log(
    calculator.next({
        operation: "multiply",
        value: 0
    }).value
);

