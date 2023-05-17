/**
 * @param {Function} fn
 */

function memoize(fn) {
  //Map for inputs
  const inputs = new Map();
  return function(...args) {

    //Convert fn arguments to a string key
    const key = JSON.stringify(args);

    //Check if this value was calulated
    if (inputs.has(key)) {
      return inputs.get(key);
    } else {
      const result = fn(...args);
      inputs.set(key, result);
      return result;
    }
  }
};