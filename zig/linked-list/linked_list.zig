const std = @import("std");

pub fn LinkedList(comptime T: type) type {
    return struct {
        pub const Node = struct {
            prev: ?*Node = null,
            next: ?*Node = null,
            data: T,
        };

        first: ?*Node = null,
        last: ?*Node = null,
        len: usize = 0,

        pub fn push(self: *LinkedList(T), node: *Node) void {
            if (self.last) |last| {
                last.next = node;
                node.prev = last;
            } else {
                self.first = node;
            }

            self.last = node;
            self.len += 1;
        }

        pub fn pop(self: *LinkedList(T)) ?*Node {
            if (self.last) |last| {
                if (last == self.first) {
                    self.first = null;
                    self.last = null;
                } else {
                    if (last.prev) |prev| prev.next = null;

                    self.last = last.prev;
                    last.prev = null;
                }

                self.len -= 1;

                return last;
            } else {
                return null;
            }
        }

        pub fn shift(self: *LinkedList(T)) ?*Node {
            if (self.first) |first| {
                if (first == self.last) {
                    self.first = null;
                    self.last = null;
                } else {
                    if (first.next) |next| next.prev = null;

                    self.first = first.next;
                    first.next = null;
                }

                self.len -= 1;

                return first;
            } else {
                return null;
            }
        }

        pub fn unshift(self: *LinkedList(T), node: *Node) void {
            if (self.first) |first| {
                first.prev = node;
                node.next = first;
            } else {
                self.last = node;
            }

            self.first = node;
            self.len += 1;
        }

        pub fn delete(self: *LinkedList(T), node: *Node) void {
            var current = self.first;

            while (current) |n| : (current = n.next) {
                if (n == node) {
                    if (n.prev) |prev| prev.next = n.next;
                    if (n.next) |next| next.prev = n.prev;
                    if (n == self.first) self.first = n.next;
                    if (n == self.last) self.last = n.prev;
                    self.len -= 1;
                    break;
                }
            }
        }
    };
}
