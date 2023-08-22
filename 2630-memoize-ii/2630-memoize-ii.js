/**
 * @param {Function} fn
 */

class Node {
  value = undefined;
  nodes = new Map();
}

class Trie {
  root = new Node();

  add(node, inputs, i, result) {
    if (i >= inputs.length) {
      node.value = result;
      return;
    }
    const currentValue = inputs[i];
    if (node.nodes.has(currentValue)) {
      return this.add(node.nodes.get(currentValue), inputs, i + 1, result);
    }
    node.nodes.set(currentValue, new Node());
    return this.add(node.nodes.get(currentValue), inputs, i + 1, result);
  }

  check(node, inputs, i) {
    if (!node) return undefined;
    if (i >= inputs.length) return node.value;
    return this.check(node.nodes.get(inputs[i]), inputs, i + 1);
  }

  addResultForInputs(inputs, result) {
    this.add(this.root, inputs, 0, result);
  }

  getResultForInputs(inputs) {
    return this.check(this.root, inputs, 0);
  }
}

function memoize(fn) {
  const trie = new Trie();
  return function (...args) {
    const memoizedValue = trie.getResultForInputs(args);
    if (memoizedValue != undefined) return memoizedValue;
    let result = fn(...args);
    trie.addResultForInputs(args, result);
    return result;
  };
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */

/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */