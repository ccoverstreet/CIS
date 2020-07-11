// string.zig: String helper functions
// Cale Overstreet
// July 1, 2020
// String helper module.

const std = @import("std");

pub const String_Array = struct {
    allocator: *std.mem.Allocator,
    size: u32 = 0,
    used: u32 = 0,
    strings: [*]u8,

    pub fn init(alloc: *std.mem.Allocator, initial_size: u32) String_Array {
        return String_Array{
            .allocator = alloc,
            .size = initial_size,
            .used = 0,
            .strings = undefined,
        };
    }

    pub fn push(self: String_Array, str: []const u8) !void {
        std.debug.warn("Str Len = {}\n", .{str.len});
        if (self.size == 0) {
            self.strings = try self.allocator.alloc(*u8, 1);
            self.size = 1;
        }

        if (self.used == self.size) {}
        self.strings[self.used] = try self.allocator.alloc(u8, str.len);
        self.strings[self.used] = std.mem.toSliceConst(u8, str);
    }
};

/// Returns true if two strings are identical and
/// false if two strings are different.
pub fn str_compare(s1: []const u8, s2: []const u8) bool {
    if (s1.len != s2.len) {
        return false;
    }

    var i: u32 = 0;
    while (i < s1.len) {
        if (s1[i] != s2[i]) {
            return false;
        }
        i = i + 1;
    }

    return true;
}

// User is responsible for returned ArrayList
pub fn str_split(allocator: *std.mem.Allocator, s1: []const u8, delimiter: u8) String_Array {
    const new_array = String_Array{ .size = 32 };
    return new_array;
}
