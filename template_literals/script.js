const users = [
    { name: "Alice", age: 53 },
    { name: "Tim", age: 74 }
];

function generateTable() {
    const table = `
        <table border="1">
            ${users.map(user => `
                <tr>
                    <td>${user.name}</td>
                    <td>${user.age}</td>
                </tr>
            `).join("")}
        </table>
    `;

    document.getElementById("table-container").innerHTML = table;
}


