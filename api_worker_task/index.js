
const worker = new Worker("worker.js");

const usersDiv = document.getElementById("users");

worker.postMessage("fetchUsers");

worker.onmessage = function(event) {

    const users = event.data;

    if (!users || users.length === 0) {
        usersDiv.innerHTML = "No users found";
        return;
    }

    users.forEach(user => {

        const userElement = document.createElement("p");

        userElement.textContent =
            `${user.name} - ${user.active ? "Active" : "Inactive"}`;

        usersDiv.appendChild(userElement);

    });

};

worker.onerror = function(error) {

    usersDiv.innerHTML = "Error fetching users";

    console.error(error.message);

};
