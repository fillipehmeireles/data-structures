#[derive(Debug)]
struct Node<T> {
    value: T,
    node: std::option::Option<Box<Node<T>>>,
}
impl<T> Node<T> {
    fn new(value: T) -> Self {
        Self { value, node: None }
    }
}
impl<T> Node<T>
where
    T: std::fmt::Debug,
{
    fn show(&mut self) {
        println!("{:#?}", self);
        if let Some(node) = self.node.as_mut() {
            node.show();
        }
    }

    fn push(&mut self, value: T) {
        if let Some(child) = self.node.as_mut() {
            child.push(value);
        } else {
            self.node = Some(Box::new(Node::new(value)));
        }
    }
}
fn main() {
    let genesis = &mut Node::new(0);
    for i in 1..10 {
        genesis.push(i);
    }
    genesis.show();
}
