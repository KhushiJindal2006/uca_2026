self.onmessage = async function (event) {

    if (event.data === "fetchUsers") {

        try {
            const response = await fetch("https://dummyjson.com/users");

            if (!response.ok) {
                throw new Error("API request failed");
            }

            const data = await response.json();

            if (!data.users || data.users.length === 0) {
                self.postMessage([]);
                return;
            }

            const users = data.users.map(user => ({
                name: user.firstName,
                active: Math.random() > 0.5
            }));

            self.postMessage(users);

        } catch (error) {
            console.error(error.message);
            self.postMessage([]);
        }
    }
};
