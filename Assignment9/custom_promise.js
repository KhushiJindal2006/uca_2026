function NewPromise(executor) {
    let state = "pending", value;
    let success = [], failure = [];

    const resolve = v => {
        if (state !== "pending") return;
        state = "fulfilled";
        value = v;
        success.forEach(fn => fn(v));
    };

    const reject = e => {
        if (state !== "pending") return;
        state = "rejected";
        value = e;
        failure.forEach(fn => fn(e));
    };

    this.then = fn => new NewPromise((resolve, reject) => {
        if (state === "fulfilled") resolve(fn(value));
        else success.push(v => resolve(fn(v)));
    });

    this.catch = fn => new NewPromise((resolve, reject) => {
        if (state === "rejected") resolve(fn(value));
        else failure.push(e => resolve(fn(e)));
    });

    executor(resolve, reject);
}
