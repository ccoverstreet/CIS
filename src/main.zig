// main.zig: CIS Entrypoint
// Cale Overstreet
// June 29, 2020
// CIS is a command line program designed to quickly parse and return values for molar mass as well as other chemical information. Currently, only molar mass is desired for output; however, CIS will be made in a way that makes it easy to extend the functionality of the program.

const std = @import("std");
const string = @import("string.zig");

pub fn main() !void {
    var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
    defer arena.deinit();

    const allocator = &arena.allocator;

    const stdin = std.io.getStdIn().inStream();
    const stdout = std.io.getStdOut().outStream();

    const str_array = string.String_Array.init(allocator, 32);
    std.debug.warn("{}\n", .{str_array});
    _ = try str_array.push("asd");

    while (true) {
        try stdout.print("[CIS v3.0.0]: ", .{});

        if (stdin.readUntilDelimiterAlloc(allocator, '\n', 100)) |input| {
            if (string.str_compare(input, "banana")) {
                try stdout.print("Hello Banana\n", .{});
            }
        } else |err| switch (err) {
            error.StreamTooLong => std.debug.warn("CIS-ERROR: Stream too long. Ignoring Input.\n", .{}),
            error.EndOfStream => std.process.exit(0),
            else => unreachable,
        }
    }
}
