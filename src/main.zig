const std = @import("std");

const img_width = 256;
const img_height = 256;

pub fn main() !void {
    // stdout is for the actual output of your application, for example if you
    // are implementing gzip, then only the compressed bytes should be sent to
    // stdout, not any debugging messages.
    const stdout_file = std.io.getStdOut().writer();
    var bw = std.io.bufferedWriter(stdout_file);
    const stdout = bw.writer();

    try stdout.print("P3\n{d} {d}\n255\n", .{ img_width, img_height });
    for (0..img_width) |j| {
        for (0..img_height) |i| {
            const iFloat: f64 = @floatFromInt(i);
            const jFloat: f64 = @floatFromInt(j);
            const r: f64 = iFloat / img_width - 1;
            const g: f64 = jFloat / img_height - 1;
            const b: f64 = 0;

            const ir: i64 = @intFromFloat(255.999 * r);
            const ig: i64 = @intFromFloat(255.999 * g);
            const ib: i64 = @intFromFloat(255.999 * b);

            try stdout.print("{d} {d} {d}\n", .{ ir, ig, ib });
        }
    }

    try bw.flush(); // don't forget to flush!
}

test "simple test" {
    var list = std.ArrayList(i32).init(std.testing.allocator);
    defer list.deinit(); // try commenting this out and see if zig detects the memory leak!
    try list.append(42);
    try std.testing.expectEqual(@as(i32, 42), list.pop());
}
