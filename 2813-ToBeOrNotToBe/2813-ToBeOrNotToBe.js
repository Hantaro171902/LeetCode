// Last updated: 7/8/2025, 11:57:53 PM
/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe: (val2) => {
            if (val !== val2) throw new Error("Not Equal");
            else return true
        },
        notToBe: (val2) => {
            if (val === val2) throw new Error("Equal");
            else return true
        }
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */