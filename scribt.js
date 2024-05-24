function calculateLIS() {
    const numElements = parseInt(document.getElementById('numElements').value);
    const arrayElements = document.getElementById('arrayElements').value.split(',').map(Number);

    if (numElements !== arrayElements.length) {
        alert('Number of elements does not match the array length');
        return;
    }

    let array1 = new Array(numElements).fill(1);
    let array2 = new Array(numElements).fill(-1);

    let max_len = 1;
    let end = 0;

    for (let i = 1; i < numElements; i++) {
        for (let j = 0; j < i; j++) {
            if (arrayElements[i] > arrayElements[j] && array1[i] < array1[j] + 1) {
                array1[i] = array1[j] + 1;
                array2[i] = j;
            }
        }
        if (array1[i] > max_len) {
            max_len = array1[i];
            end = i;
        }
    }

    traceAndPrintLIS(arrayElements, array2, end, max_len);
}

function traceAndPrintLIS(nums, prev, end_point, max_len) {
    let lis = [];

    while (end_point !== -1) {
        lis.push(nums[end_point]);
        end_point = prev[end_point];
    }
    lis.reverse();

    document.getElementById('lisLength').innerText = `Length of LIS: ${max_len}`;
    document.getElementById('lisArray').innerText = `The longest increasing subsequence is:{${lis.join(',')}}`;
}
