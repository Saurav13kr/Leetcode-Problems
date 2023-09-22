/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    let result = [];
    if(n === 0) return arr;
    for(let item of arr){
        if(Array.isArray(item)){
            result.push(...flat(item, n - 1));
        }
        else{
            result.push(item);
        }
    }
    return result;
}